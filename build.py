import glob
import shutil
import subprocess
import os
import sys


def err(message: str):
    print(f"Error: {message}")
    sys.exit(1)

def build(region, includes=["include"]):
    syati_root = os.path.dirname(__file__)

    # Check if CodeWarrior and Kamek are present in the toolchain
    command = syati_root + "/CodeWarrior/mwcceppc.exe"
    if not os.path.exists(command):
        err("CodeWarrior compiler not found.")
    asm_cmd = syati_root + "/CodeWarrior/mwasmeppc.exe"
    if not os.path.exists(asm_cmd):
        err("CodeWarrior assembler not found.")
    kamek_cmd = syati_root + "/Kamek/Kamek.exe"
    if not os.path.exists(kamek_cmd):
        err("Kamek linker not found.")

    # Define the compiler options and command
    compiler_options = [
        "-i .",
        "-I-"
    ]

    for include in includes:
        compiler_options.append("-i " + include)

    assembler_options = compiler_options[:]

    compiler_options += [
        "-nodefaults",
        "-proc gekko",
        "-Cpp_exceptions off",
        "-enum int",
        "-O4,s",
        "-fp hard",
        "-func_align 4",
        "-str pool",
        "-sdata 0",
        "-sdata2 0",
        f"-D{region}",
        "-DGEKKO",
        "-DMTX_USE_PS",
        "-MMD",
        "-rtti off",
        "-c",
        "-o"
    ]

    assembler_options += [
        "-proc gekko",
        "-c",
        f"-D{region}",
        "-o"
    ]

    if os.name != 'nt':
        command = "wine " + command
        asm_cmd = "wine " + asm_cmd
        kamek_cmd = "mono " + kamek_cmd

    command += " " + " ".join(compiler_options)
    asm_cmd += " " + " ".join(assembler_options)

    # Clean the entire build folder first if it exists
    if os.path.exists("build"):
        shutil.rmtree("build", ignore_errors=True)

    # Fetch all source C++ files that need to be compiled
    tasks = list()
    asm_tasks = list()

    for root, dirs, files in os.walk("source"):
        for file in files:
            if file.endswith(".cpp"):
                source_path = os.path.join(root, file)
                build_path = source_path.replace("source", "build").replace(".cpp", ".o")

                os.makedirs(os.path.dirname(build_path), exist_ok=True)

                tasks.append((source_path, build_path))
            elif file.endswith(".s"):
                source_path = os.path.join(root, file)
                build_path = source_path.replace("source", "build").replace(".s", ".o")

                os.makedirs(os.path.dirname(build_path), exist_ok=True)

                asm_tasks.append((source_path, build_path))

    if len(tasks) < 1:
        err("No C++ files to compile!")


    # Process all compile tasks
    for task in tasks:
        source_path, build_path = task

        print(f"Compiling {source_path}...")

        if subprocess.call(f"{command} {build_path} {source_path}", shell=True) != 0:
            err("Compiler error.")

    for a_task in asm_tasks:
        source_path, build_path = a_task

        print(f"Assembling {source_path}...")

        if subprocess.call(f"{asm_cmd} {build_path} {source_path}", shell=True) != 0:
            err("Assembler error.")

    # Link all object files and create the CustomCode binary
    print("Linking...")

    object_files = " ".join([task[1] for task in tasks])
    asm_obj_files = " ".join([a_task[1] for a_task in asm_tasks])

    kamek_cmd += f" {object_files} {asm_obj_files} -externals={syati_root}/symbols/{region}.txt -output-kamek=CustomCode_{region}.bin"

    if subprocess.call(kamek_cmd, shell=True) != 0:
        err("Linking failed.")

    # Remove all useless "d" files
    for f in glob.glob("*.d"):
        os.remove(f)

    print("Done!")

if __name__ == '__main__':
    # Get the target region from the command line
    if len(sys.argv) < 2:
        err("Did not specify a target region.")

    build(sys.argv[1])
