@echo off

REM build SharpDevelop using the releasebuild.bat file

REM set directory
set testdata=..\..\TestData

cd   "%testdata%\SharpDevelop\src"

REM if exist build  (
REM echo deleting build files
REM del  /s /q  build  > NUL
REM )

call releasebuild.bat

echo -
pause