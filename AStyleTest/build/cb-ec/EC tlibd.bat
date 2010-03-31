@echo off

REM This file runs TLIB with quotes around the onbect file path.
REM The dash (-) in the pathname apparently is mistaken for a minus sign.
REM File paths without a dash work ok with TLIB.

@set binpath=C:\Programs\Embarcadero\EC62\bin

@if exist bin\gtestd.lib del  bin\gtestd.lib

@echo Linking gtestd.lib

@%binpath%\tlib.exe /C /P32 bin\gtestd.lib + "objd\gtest-1.4.0\src\gtest-filepath.obj" + "objd\gtest-1.4.0\src\gtest-port.obj" + "objd\gtest-1.4.0\src\gtest-test-part.obj" +   "objd\gtest-1.4.0\src\gtest-typed-test.obj" + "objd\gtest-1.4.0\src\gtest.obj" + "objd\gtest-1.4.0\src\gtest-death-test.obj"

REM @echo -
REM @pause
