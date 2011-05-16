@echo off

set projdir=%USERPROFILE%\Projects\AStyle

set linedir=C:\Programs\LineEnds

REM check for line-end conversion programs
:checkProg
if not exist "%linedir%\dos2unix.exe" (
echo -
echo need program dos2unix
echo -
pause
goto :checkProg
)

if exist "%projdir%\DistBase"  rd  "%projdir%\DistBase"  /q /s
if exist "%projdir%\DistBase"  pause
if exist "%projdir%\DistLinux"  rd  "%projdir%\DistLinux"  /q /s
if exist "%projdir%\DistLinux"  pause
if exist "%projdir%\DistMac"  rd  "%projdir%\DistMac"  /q /s
if exist "%projdir%\DistMac"  pause
if exist "%projdir%\DistWindows"  rd  "%projdir%\DistWindows"  /q /s
if exist "%projdir%\DistWindows"  pause
if exist "%projdir%\DistVMS"  rd  "%projdir%\DistVMS"  /q /s
if exist "%projdir%\DistVMS"  pause

REM the Base distribution is everything except the build files
REM files are converted to Linux lineends
echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *               Copying Base Distribution               *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
cd  "%projdir%"
md  DistBase\astyle

REM doc directory
cd  "%projdir%"
md  DistBase\astyle\doc
cd  DistBase\astyle\doc
for %%v in (astyle.html
            download.html
            index.html
            install.html
            license.html
            links.html
            news.html
            notes.html
            scripts.html
            styles.css) do (
xcopy "%projdir%\doc\%%v"  /q
if errorlevel 2 pause
REM convert line ends
"%linedir%\dos2unix"  "%%v"
if errorlevel 1 pause
)

REM src directory
cd  "%projdir%"
md  DistBase\astyle\src
cd  DistBase\astyle\src
for %%v in (ASBeautifier.cpp
            ASEnhancer.cpp
            ASFormatter.cpp
            ASResource.cpp
            astyle_main.cpp
            astyle.h
            astyle_main.h) do (
xcopy "%projdir%\src\%%v"  /q
if errorlevel 2 pause
REM convert line ends
"%linedir%\dos2unix"  "%%v"
if errorlevel 1 pause
)

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *               Copying Linux Distribution              *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
cd  "%projdir%"
md  DistLinux

REM copy Base distribution
cd  "%projdir%\DistLinux"
xcopy "%projdir%\DistBase"  /q /e
if errorlevel 2 pause
echo DistBase copied

REM build directory
cd  "%projdir%\build"
for %%v in (gcc
            intel) do (
md  "%projdir%\DistLinux\astyle\build\%%v"
cd  "%projdir%\DistLinux\astyle\build\%%v"
xcopy "%projdir%\build\%%v\Makefile"  /q
if errorlevel 2 pause
	if %%v == intel (
	xcopy "%projdir%\build\%%v\make.sh"  /q
	if errorlevel 2 pause
	)
)
echo build files copied

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *               Copying Mac Distribution                *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
cd  "%projdir%"
md  DistMac

REM copy Base distribution
cd  "%projdir%\DistMac"
xcopy "%projdir%\DistBase"  /q /e
if errorlevel 2 pause
echo DistBase copied

REM build directory
cd  "%projdir%"
md  "%projdir%\DistMac\astyle\build\mac"
cd  "%projdir%\DistMac\astyle\build\mac"
xcopy "%projdir%\build\mac\Makefile"  /q
if errorlevel 2 pause
echo build files copied

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *             Copying OpenVMS Distribution              *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
cd  "%projdir%"
md  DistVMS

REM copy Base distribution
cd  "%projdir%\DistVMS"
xcopy "%projdir%\DistBase"  /q /e
if errorlevel 2 pause
echo DistBase copied

REM build directory
cd  "%projdir%\build"
md  "%projdir%\DistVMS\astyle\build\vms"
cd  "%projdir%\DistVMS\astyle\build\vms"
for %%v in (descrip.mms
            java.opt
            lib.opt
            vmsbuild.com) do (
xcopy "%projdir%\build\vms\%%v"  /q
if errorlevel 2 pause
)
echo build files copied

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *              Copying Windows Distribution             *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
cd  "%projdir%"
md  DistWindows

REM copy Base distribution
cd  "%projdir%\DistWindows"
xcopy "%projdir%\DistBase"  /q /e
if errorlevel 2 pause
echo DistBase copied

REM convert line ends
for /R  %%v   in (*.*)  do (
"%linedir%\unix2dos"  "%%v"  > NUL
echo Unix2Dos: %%~nxv
)
echo Lineends converted

REM Windows includes an executable in the bin directory
cd  "%projdir%"
md  DistWindows\astyle\bin
cd  DistWindows\astyle\bin
xcopy "%projdir%\build\vs2008\binstatic\AStyle.exe"  /q
if errorlevel 2 pause
echo executable copied

REM build\vs2003 directory
cd  "%projdir%\build"
for %%v in (vs2003) do (
md  "%projdir%\DistWindows\astyle\build\%%v"
cd  "%projdir%\DistWindows\astyle\build\%%v"
REM copy the files
xcopy "%projdir%\build\%%v\AStyle.sln"  /q
if errorlevel 2 pause
xcopy "%projdir%\build\%%v\AStyle.vcproj"  /q
if errorlevel 2 pause
)
echo build\vs2003 copied

REM build directory
cd  "%projdir%\build"
for %%v in (vs2005
            vs2008
			vs2010) do (
md  "%projdir%\DistWindows\astyle\build\%%v"
cd  "%projdir%\DistWindows\astyle\build\%%v"
REM copy the files
xcopy "%projdir%\build\%%v\*.sln"  /q
if errorlevel 2 pause
for %%w in (AStyle
            AStyleDll
			AStyleJava
			AStyleLib) do (
md  "%projdir%\DistWindows\astyle\build\%%v\%%w"
xcopy "%projdir%\build\%%v\%%w\*.vc*proj"  %%w\  /q
if errorlevel 2 pause
if /i  %%v GEQ vs2010 (
xcopy "%projdir%\build\%%v\%%w\*.filters"  %%w\  /q
if errorlevel 2 pause
)
)
echo build\%%v copied
)


echo -
echo -
echo * * * *  end of dist-copy  * * * *
pause
