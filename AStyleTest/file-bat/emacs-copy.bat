@echo off

REM copy selected files to the test directory for emacs-test.bat

REM variables
set filedir=..\..\EmacsTest

set testdir=..\..\TestData
set asdir=..\..\AStyle


echo -
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
echo *               Copying Emacs Test Files                *
echo * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
if exist "%filedir%" (
	del "%filedir%\*.*"  /q
)

xcopy "%asdir%\src\ASFormatter.cpp"  "%filedir%\"  /q
xcopy "%asdir%\src\astyle.h"         "%filedir%\"  /q

xcopy "%testdir%\jEdit\org\gjt\sp\jedit\TextUtilities.java"  "%filedir%"  /q

REM "switch" statements
xcopy "%testdir%\SharpDevelop\src\AddIns\BackendBindings\Python\PythonBinding\Project\Src\NRefactoryToPythonConverter.cs"  "%filedir%"  /q
REM "});" at about line 147 - full indent
xcopy "%testdir%\SharpDevelop\src\AddIns\BackendBindings\Boo\BooBinding\Project\Src\Designer\BooDesignerLoader.cs"  "%filedir%"  /q
REM "});" at about line 79 - no indent
xcopy "%testdir%\SharpDevelop\src\AddIns\BackendBindings\VBNetBinding\Project\Src\MyNamespaceBuilder.cs"  "%filedir%"  /q

echo -
echo -
pause
