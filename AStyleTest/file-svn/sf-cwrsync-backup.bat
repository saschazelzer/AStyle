@ECHO OFF
REM *****************************************************************
REM
REM CWRSYNC.CMD - Batch file template to start your rsync command (s).
REM
REM By Tevfik K. (http://itefix.no)
REM *****************************************************************

REM Make environment variable changes local to this batch file
SETLOCAL

REM ** CUSTOMIZE ** Specify where to find rsync and related files (C:\CWRSYNC)
SET CWRSYNCHOME=%PROGRAMFILES%\CWRSYNC

REM Set CYGWIN variable to 'nontsec'. That makes sure that permissions
REM on your windows machine are not updated as a side effect of cygwin
REM operations.
SET CYGWIN=nontsec

REM Set HOME variable to your windows home directory. That makes sure 
REM that ssh command creates known_hosts in a directory you have access.
SET HOME=%HOMEDRIVE%%HOMEPATH%

REM Make cwRsync home as a part of system PATH to find required DLLs
SET CWOLDPATH=%PATH%
SET PATH=%CWRSYNCHOME%\BIN;%PATH%

REM Windows paths may contain a colon (:) as a part of drive designation and 
REM backslashes (example c:\, g:\). However, in rsync syntax, a colon in a 
REM path means searching for a remote host. Solution: use absolute path 'a la unix', 
REM replace backslashes (\) with slashes (/) and put -/cygdrive/- in front of the 
REM drive letter:
REM 
REM Example : C:\WORK\* --> /cygdrive/c/work/*
REM 
REM Example 1 - rsync recursively to a unix server with an openssh server :
REM
REM       rsync -r /cygdrive/c/work/ remotehost:/home/user/work/
REM
REM Example 2 - Local rsync recursively 
REM
REM       rsync -r /cygdrive/c/work/ /cygdrive/d/work/doc/
REM
REM Example 3 - rsync to an rsync server recursively :
REM    (Double colons?? YES!!)
REM
REM       rsync -r /cygdrive/c/doc/ remotehost::module/doc
REM
REM Rsync is a very powerful tool. Please look at documentation for other options. 
REM

REM ** CUSTOMIZE ** Enter your rsync command(s) here * * * * * * * * * * * * *

color 0B
PATH=%PATH%;%PROGRAMFILES%\7-Zip

REM do NOT use backslashes in the file paths
REM do NOT use %USERPROFILE% becaue of the backslashes
set mirror=/cygdrive/C/Users/%USERNAME%/Backup/Mirror

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                   Copying SVN Files                   * 
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
rsync -av  astyle.svn.sourceforge.net::svn/astyle/*  %mirror%
if errorlevel 1 pause

echo -
echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *                  Creating SVN Backup                  * 
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
set today=%date:~4%
set infile=C:%mirror:~11%
set outpath=%USERPROFILE%\Backup
set outfile=mirror-%today:~0,2%-%today:~3,2%

7z  a  "%outpath%\%outfile%"  "%infile%" > NUL
if errorlevel 1 pause


echo -
echo -
echo * * * * *  end of backup * * * * *
pause

