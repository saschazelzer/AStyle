@color 0B
@cd \

@set today=%date:~4%
set fromDate=%today%
:: set fromDate=03/05/2006

@echo off

REM set path variables
set projects=%USERPROFILE%\Projects\TestSvn\Projects
REM the following variable must be %backup%
REM projects.bat must work with both dump.bat and remote.bat
set backup=%USERPROFILE%\Projects\TestSvn\Updates
REM Rapid SVN is NOT backed up to remote so do it here instead of in projects.bat

if exist "%backup%" (
echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *              Removing Updates Directory               *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
rd "%backup%"  /s /q
:: pause if it wasn't removed
if exist "%backup%" pause
)

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                   Copying SVN Files                   * 
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

REM copy AStyle SVN
REM if updated copy all files in text-base
if exist "%projects%\AStyle" (
echo copying AStyle files
for /d %%v in (AStyle
               AStyle\build
               AStyle\doc
               AStyle\src
               AStyle\build\gcc
               AStyle\build\intel
               AStyle\build\mac
               AStyle\build\vs2003
               AStyle\build\vs2005
               AStyle\build\vs2008)  do (
xcopy "%projects%\%%v\.svn"  "%backup%\Projects\%%v\.svn\"  /q /d:%fromDate%
if errorlevel 2 pause
if exist  "%backup%\Projects\%%v\.svn\entries"  (
    if exist  "%backup%\Projects\%%v\.svn\text-base\*"  del  "%backup%\Projects\%%v\.svn\text-base\*"  /q
    xcopy "%projects%\%%v\.svn\text-base"  "%backup%\Projects\%%v\.svn\text-base\"  /q
    if errorlevel 2 pause
    )
)
)

REM copy AStyleDev SVN
REM if updated copy all files in text-base
if exist "%projects%\AStyleDev" (
echo copying AStyleDev files
for /d %%v in (AStyleDev
               AStyleDev\build
               AStyleDev\doc
               AStyleDev\file-bat
               AStyleDev\file-sh
               AStyleDev\scripts
               AStyleDev\src-c
               AStyleDev\src-cx
               AStyleDev\src-cxx
               AStyleDev\src-j
               AStyleDev\src-jx
			   AStyleDev\src-s
			   AStyleDev\src-sx
			   AStyleDev\test-c
			   AStyleDev\test-j
			   AStyleDev\test-s
			   AStyleDev\build\cb-borland
			   AStyleDev\build\cb-dmars
               AStyleDev\build\cb-gcc
               AStyleDev\build\cb-intel
               AStyleDev\build\cb-mingw
			   AStyleDev\build\vs2005
               AStyleDev\build\vs2008)  do (
xcopy "%projects%\%%v\.svn"  "%backup%\Projects\%%v\.svn\"  /q /d:%fromDate%
if errorlevel 2 pause
if exist  "%backup%\Projects\%%v\.svn\entries"  (
    if exist  "%backup%\Projects\%%v\.svn\text-base\*"  del  "%backup%\Projects\%%v\.svn\text-base\*"  /q
    xcopy "%projects%\%%v\.svn\text-base"  "%backup%\Projects\%%v\.svn\text-base\"  /q
    if errorlevel 2 pause
    )
)
)

REM copy AStyleTest SVN
REM if updated copy all files in text-base
if exist "%projects%\AStyleTest" (
echo copying AStyleTest files
for /d %%v in (AStyleTest
               AStyleTest\build
               AStyleTest\file-bat
               AStyleTest\file-sh
               AStyleTest\file-svn
               AStyleTest\src
               AStyleTest\build\cb-gcc
               AStyleTest\build\cb-intel
               AStyleTest\build\cb-mingw
               AStyleTest\build\vs2008)  do (
xcopy "%projects%\%%v\.svn"  "%backup%\Projects\%%v\.svn\"  /q /d:%fromDate%
if errorlevel 2 pause
if exist  "%backup%\Projects\%%v\.svn\entries"  (
    if exist  "%backup%\Projects\%%v\.svn\text-base\*"  del  "%backup%\Projects\%%v\.svn\text-base\*"  /q
    xcopy "%projects%\%%v\.svn\text-base"  "%backup%\Projects\%%v\.svn\text-base\"  /q
    if errorlevel 2 pause
    )
)
)


echo -
echo -
echo * * * * * *  end of dump  * * * * * *
pause
