@echo off

set astyle=..\..\AStyle\build\vs2008\bin\AStyle

%astyle%  -vR -F < test11.cpp > test112.cpp

echo -
pause
