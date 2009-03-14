@echo off
REM checkout the files to a working copy

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=C:/Users/jp/Projects/TestSvn/Repository
set svndir=%repos%/trunk
set projdir=%USERPROFILE%\Projects\TestSvn\Projects


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo checkout AStyle
echo --------------------------
svn  checkout  "file:///%svndir%/AStyle"  "%projdir%/AStyle"


echo -
echo -
echo * * * * *  end of checkout * * * * *
pause
