IF [%1] == [] echo The first argument must be a galaxy region! && exit

SET CXX="%CD%\CodeWarrior\mwcceppc.exe"

SET CXX_FLAGS=-i . -I- -i include -nodefaults -proc gekko -Cpp_exceptions off -enum int -O4,s -fp hard -func_align 4 -str pool -sdata 0 -sdata2 0 -D%1 -DGEKKO -DMTX_USE_PS -MMD -rtti off -c -o

SET ASM_FLAGS=-i . -I- -i include -proc gekko -c -D%1 -o

SET LD="%CD%\Kamek\Kamek.exe"

SET LD_FLAGS=-externals=symbols/%1.txt -output-kamek=CustomCode_%1.bin

if "%2"=="PT" mv source\ExtendedActorFactory.cpp "%CD%"

PowerShell Get-ChildItem -Path .\source -Filter *.cpp -Recurse -File -Name > cppfiles.txt

for /F "tokens=*" %%A in (cppfiles.txt) do %CXX% %CXX_FLAGS% build/%%~nA.o source\%%A

rm -f *.d

rm cppfile.txt

make > lines.txt

set /p OFILES=< lines.txt

rm lines.txt

%LD% %OFILES% %LD_FLAGS%

rm -f build/*.o

if "%2"=="PT" mv ExtendedActorFactory.cpp source
