#!/bin/bash
# test the C# programs on Mac

# for testing on Linux (0 or 1)
linux=1
# define $result variable here
result=:
unset result

echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "*                       compile shared library                        *"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
cd  $HOME/Projects/AStyle/build/mac
if [ $linux == 1 ]; then
	make  shared  linux=1
else
	make  shared 
fi
result=$?; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error compiling! "; echo; fi
unset result

echo "Copying . . ."
if [ $linux == 1 ]; then
	dylib=so
else
	dylib=dylib
fi
cp  --preserve --force --verbose  bin/libastyle.$dylib  $HOME//Projects/AStyleDev/src-s
cp  --preserve --force --verbose  bin/libastyle.$dylib  $HOME//Projects/AStyleDev/src-sx

echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "*                              test src-s                             *"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
cd  $HOME/Projects/AStyleDev/src-s
echo "Compiling . . ."
# mcs is version 1.1 compile, gmcs is version 2.0 compile
gmcs  /warn:4  /t:winexe  /out:Example.exe  *.cs  /r:System,System.Drawing
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error compiling! "; echo; fi
unset result

echo "Testing . . ."
mono  Example.exe
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error on test! "; echo; fi
unset result

echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "*                              test src-sx                            *"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
cd  $HOME/Projects/AStyleDev/src-sx
echo "Compiling . . ."
# mcs is version 1.1 compile, gmcs is version 2.0 compile
gmcs  /warn:4  /t:winexe  /out:Example.exe  *.cs  /r:System,System.Drawing
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error compiling! "; echo; fi
unset result

echo "Testing . . ."
mono  Example.exe
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error on test! "; echo; fi
unset result

echo