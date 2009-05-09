@echo off
REM copy all file types to MergeTest folder for testing

set testdata=..\..\TestData

REM remove MergeTest
if exist "%testdata%\MergeTest" (
echo -
echo Removing MergeTest directory
rmdir  /s  "%testdata%\MergeTest"
)
REM exit if not removed
if exist "%testdata%\MergeTest"  exit

echo -
echo copying C++
xcopy "%testdata%\CodeBlocks\src\*.cpp"  "%testdata%\MergeTest\"  /s /q
xcopy "%testdata%\CodeBlocks\src\*.h"    "%testdata%\MergeTest\"  /s /q
echo -
echo copying C#
xcopy "%testdata%\Sharpdevelop\src\*.cs" "%testdata%\MergeTest\"  /s /q
echo -
echo copying Java
xcopy "%testdata%\jEdit\*.java"          "%testdata%\MergeTest\"  /s /q

echo -
pause
