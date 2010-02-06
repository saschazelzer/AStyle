#!/bin/bash
# build the AStyle Release Java Configuration using the AStyle makefile
# copy the output to the AStyleDev\test-j(x) folder

astyle=$HOME/Projects/AStyle/build/gcc
bindir1=$HOME/Projects/AStyleDev/src-j
bindir2=$HOME/Projects/AStyleDev/src-jx
errors=no

#define $result variable here
result=:
unset result

echo
echo BUILDING ASTYLE JAVA
cd  $astyle
make  java
result=$?
if [ $result -ne 0 ]; then  errors=yes; echo; fi
unset result

# don't copy if compile errors
if [ $errors==no ]; then
	echo COPYING
	cp  --verbose  bin/libastylej.so  $bindir1/ 
	result=$?
	if [ $result -ne 0 ]; then  errors=yes; fi
	unset result
	cp  --verbose  bin/libastylej.so $bindir2/
	result=$?
	if [ $result -ne 0 ]; then  errors=yes; fi
	unset result
fi

if [ $errors = yes ]; then
	echo
	echo "* * * *  ERRORS IN PROCESSING SCRIPT  * * * *"
fi

echo 

if [ ! $1 ]; then
	read -sn1 -p "Press Enter to end "
	echo
fi
