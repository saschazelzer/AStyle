@echo off

REM This file runs TLIB with quotes around the object file path.
REM The dash (-) in the pathname apparently is mistaken for a minus sign.
REM File paths without a dash work ok with TLIB.

set binpath=C:\Programs\Embarcadero\EC62\bin

if exist bin\gtestd.lib del  bin\gtestd.lib

echo Linking gtestd.lib

%binpath%\tlib.exe /C /P64 bin\gtestd.lib + "objGTd\gmock\gtest\src\gtest-filepath.obj" + "objGTd\gmock\gtest\src\gtest-port.obj" + "objGTd\gmock\gtest\src\gtest-test-part.obj" +   "objGTd\gmock\gtest\src\gtest-typed-test.obj" + "objGTd\gmock\gtest\src\gtest.obj" + "objGTd\gmock\gtest\src\gtest-death-test.obj"

REM echo -
REM pause
