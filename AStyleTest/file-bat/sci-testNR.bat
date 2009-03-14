@echo off

set testdata=..\..\TestData\scite
set astyledir=..\..\AStyle

:: set progdir=%astyledir%\build\cb-borland\bin
:: set progdir=%astyledir%\build\cb-dmars\bin
:: set progdir=%astyledir%\build\cb-mingw\bin
:: set progdir=%astyledir%\build\vs2003\bin
:: set progdir=%astyledir%\build\vs2005\bin
set progdir=%astyledir%\build\vs2008\bin


:: %progdir%\AStyle.exe -h
:: %progdir%\AStyle.exe -V

:: set ARTISTIC_STYLE_OPTIONS=.\astylerc

set opts=
::set opts=-CSKBGNLwM50m10FepPUoOcE

for /d %%v in (scintilla\gtk
               scintilla\include
			   scintilla\macosx
               scintilla\src
               scintilla\win32
			   scite\gtk
               scite\src
               scite\win32)  do (		   
%progdir%\AStyle  %opts%  "%testdata%\%%v\*.cxx"  "%testdata%\%%v\*.h"
)

echo -
pause
