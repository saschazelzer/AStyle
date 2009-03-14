@echo off
REM merge the web documentation branch with the current AStyle documentation

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set svndir=C:/Users/jp/Projects/TestSvn/Repository
set projdir=%USERPROFILE%\Projects\TestSvn\Projects


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo merging AStyleWeb/doc copies
echo --------------------------
cd  %projdir%\AStyle\doc
svn  merge  "file:///%svndir%/branches/AStyleWeb/doc"  "file:///%svndir%/AStyle/doc"


echo -
echo -
echo * * * * *  end of merge doc  * * * * *
pause
