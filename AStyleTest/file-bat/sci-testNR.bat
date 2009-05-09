@echo off

set testdata=..\..\TestData\scite

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\bin\AStyled

:: set options= -HvRQ
:: set options= -bCSKBGNLwM50m10yeoOcFpPHUxEvRQ
REM without indent-blocks or indent-brackets (B or G)
set options= -gCSKNLwM50m10yeoOcFpPHUxEvRQ


call  libCompile.bat  %astyle%
echo Formatting SciTE %options%

for /d %%v in (scintilla\gtk
               scintilla\include
			   scintilla\macosx
               scintilla\src
               scintilla\win32
			   scite\gtk
               scite\src
               scite\win32)  do (		   
%astyle%  %options%  "%testdata%\%%v\*.cxx"  "%testdata%\%%v\*.h"
)

echo -
pause
