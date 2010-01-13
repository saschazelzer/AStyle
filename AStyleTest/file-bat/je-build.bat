@echo off

REM build jEdit using ant

REM build.properties.sample must be modified to 
REM build.dir=build and dist.dir=dist (not used)
REM and saved as build.properties

REM set directory of build.properties and build.xml
set testdata=..\..\TestData

REM set variables for ant
set ANT_HOME=%PROGRAMFILES%\Java\apache-ant-1.7.1
set JAVA_HOME=%PROGRAMFILES%\Java\jdk1.6.0_17
set PATH=%PATH%;%ANT_HOME%\bin

if not exist "%testdata%\jEdit" (
echo no directory "%testdata%\jEdit"
pause
exit
)

cd   "%testdata%\jEdit"

if exist build  (
echo deleting build files
del  /s /q  build  > NUL
)

REM must start a separate process so the window does not close at EOJ
echo starting build in a separate process
start  ant  build

echo -
pause