@echo off
REM merge the web documentation branch with the current AStyle documentation

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=https://astyle.svn.sourceforge.net/svnroot/astyle
set projdir=%USERPROFILE%\Projects


REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo merging AStyleWeb/doc copies
echo --------------------------
cd  %projdir%\AStyle\doc
svn  merge  "%repos%/branches/AStyleWeb/doc"  "%repos%/trunk/AStyle/doc"


echo -
echo -
echo * * * * *  end of merge doc  * * * * *
pause
