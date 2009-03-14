@echo off
REM checkout the files to a working copy

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=C:/Users/jp/Projects/TestSvn/Repository
set svndir=%repos%/branches
set projdir=%USERPROFILE%\Projects\TestSvn\Projects


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo checkout AStyleTest
echo --------------------------
svn  checkout  "file:///%svndir%/AStyleTest"  "%projdir%/AStyleTest"


echo -
echo -
echo * * * * *  end of checkout * * * * *
pause
