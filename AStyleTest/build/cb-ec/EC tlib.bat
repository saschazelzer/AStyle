@echo off

REM This file runs TLIB with quotes around the onbect file path.
REM The dash (-) in the pathname apparently is mistaken for a minus sign.
REM File paths without a dash work ok with TLIB.

@set binpath=C:\Programs\Embarcadero\EC62\bin

@if exist bin\gtestd.lib del  bin\gtest.lib

@echo Linking gtest.lib

@%binpath%\tlib.exe /C /P32 bin\gtest.lib + "objGT\gtest\src\gtest-filepath.obj" + "objGT\gtest\src\gtest-port.obj" + "objGT\gtest\src\gtest-test-part.obj" +   "objGT\gtest\src\gtest-typed-test.obj" + "objGT\gtest\src\gtest.obj" + "objGT\gtest\src\gtest-death-test.obj"

REM @echo -
REM @pause
