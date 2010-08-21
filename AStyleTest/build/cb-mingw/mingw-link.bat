@echo off
REM Create a gmock link to the needed mingw dlls
REM these are NOT needed if executed from CodeBlocks
REM These ARE needed if not executed from CodeBlocks

set progdir=C:\Programs\MinGW\bin

if not exist bin\libgcc_s_dw2-1.dll  mklink  /H  bin\libgcc_s_dw2-1.dll  %progdir%\libgcc_s_dw2-1.dll

if not exist bin\libstdc++-6.dll  mklink  /H  bin\libstdc++-6.dll  %progdir%\libstdc++-6.dll

::echo -
::pause
