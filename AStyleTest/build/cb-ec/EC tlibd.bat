@echo off

REM This file runs TLIB with quotes around the onbect file path.
REM The dash (-) in the pathname apparently is mistaken for a minus sign.
REM File paths without a dash work ok with TLIB.

@set binpath=C:\Programs\Embarcadero\EC62\bin

@if exist bin\gtestd.lib del  bin\gtestd.lib

@echo Linking gtestd.lib

@%binpath%\tlib.exe /C /P64 bin\gtestd.lib + "objGTd\gtest\src\gtest-filepath.obj" + "objGTd\gtest\src\gtest-port.obj" + "objGTd\gtest\src\gtest-test-part.obj" +   "objGTd\gtest\src\gtest-typed-test.obj" + "objGTd\gtest\src\gtest.obj" + "objGTd\gtest\src\gtest-death-test.obj"

REM @echo -
REM @pause
