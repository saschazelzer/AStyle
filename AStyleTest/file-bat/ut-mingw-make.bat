@echo off
REM use the unittest++ gcc makefile to make the mingw32 library libUnitTest++.a

REM unittest++ gcc makefile is modified as follows:
REM remove -ansi from line 2  --  CXXFLAGS ?= -g -Wall -W -ansi # -pedantic
REM remove line 89  -  @$(call make-depend,$<,$@,$(subst .o,.d,$@))
REM the variable MSYSTEM=MINGW32 is defined below

set utdir=%USERPROFILE%\Projects\UnitTest++

set PATH=C:\Programs\MinGW\bin;PATH
set MSYSTEM=MINGW32

REM copy mingw makefileto the unittest++ directory
if not exist "%utdir%\ut-mingw-makefile"  copy "ut-mingw-makefile" "%utdir%"

cd %utdir%

echo BUILDING MINGW32
mingw32-make  -f  ut-mingw-makefile

echo -
echo CLEANING MINGW32
del  src\*.o


echo -
pause
