@REM make example2 program distribution directories
@echo off

set progdir=C:\Program Files (x86)\Microsoft Visual Studio 8\VC\bin\amd64

set filepath=..\..\AStyle\build\vs2005\x64\debug\AStyled.dll

"%progdir%\dumpbin"  /EXPORTS  "%filepath%"

echo -
echo -
echo * * * *  end of dumpbin  * * * *
pause
