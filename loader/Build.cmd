SET CXX="%CD%\..\CodeWarrior\mwcceppc.exe"

SET CXX_FLAGS=-i . -I- -i ../include -Cpp_exceptions off -enum int -O4,s -use_lmw_stmw on -fp hard -func_align 4 -str pool -rostr -sdata 0 -sdata2 0 -D%1 -c -o

SET DOL="%CD%\..\dols\%1.dol"

SET LD="%CD%\..\Kamek\Kamek.exe"

SET LD_FLAGS=-static=0x80001800 -output-riiv=out/riivo_%1.xml -input-dol=%DOL% -output-dol=out/%1.dol

PowerShell Get-ChildItem -Path .\ -Filter *.cpp -Recurse -File -Name > cppfiles.txt

for /F "tokens=*" %%A in (cppfiles.txt) do %CXX% %CXX_FLAGS% %%~nA.o %%A

rm cppfiles.txt

make -f old.mak > lines.txt

set /p OFILES=< lines.txt

rm lines.txt

mkdir out

%LD% %OFILES% %LD_FLAGS%

rm -f *.o