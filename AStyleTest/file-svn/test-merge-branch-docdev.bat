@echo off
REM merge the web development documentation branch with the current AStyle documentation

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set svndir=C:/Users/jp/Projects/TestSvn/Repository
set projdir=%USERPROFILE%\Projects\TestSvn\Projects


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo merging AStyleWebDev/doc copies
echo --------------------------
cd  %projdir%\AStyleDev\doc
svn  merge  "file:///%svndir%/branches/AStyleWeb/doc-dev"  "file:///%svndir%/AStyleDev/doc"


echo -
echo -
echo * * * *  end of merge docdev  * * * *
pause
