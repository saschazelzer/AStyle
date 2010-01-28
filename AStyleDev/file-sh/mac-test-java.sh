#!/bin/bash
# test the Java programs on Mac

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
	make  java  linux=1
else
	make  java 
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
cp  --preserve --force --verbose  bin/libastylej.$dylib  $HOME//Projects/AStyleDev/src-j
cp  --preserve --force --verbose  bin/libastylej.$dylib  $HOME//Projects/AStyleDev/src-jx

echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "*                              test src-j                             *"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
cd  $HOME/Projects/AStyleDev/src-j
echo "Compiling . . ."
javac  *.java
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error compiling! "; echo; fi
unset result

echo "Testing . . ."
java -classpath $HOME/Projects/AStyleDev/src-j  Example
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error on test! "; echo; fi
unset result

echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "*                              test src-jx                            *"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
cd  $HOME/Projects/AStyleDev/src-jx
echo "Compiling . . ."
javac  *.java
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error compiling! "; echo; fi
unset result

echo "Testing . . ."
java -classpath $HOME/Projects/AStyleDev/src-j  Example
result=$?; echo; echo RESULT=$result; echo
if [ $result -ne 0 ]; then  read -sn1 -p "Error on test! "; echo; fi
unset result

echo