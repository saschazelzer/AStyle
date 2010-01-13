#!/bin/bash
# test the astyle console program

exedir=$HOME/Projects/astyle/_cb-gcc/bin
srcdir=$HOME/Projects/astyle/src
testdir=$HOME/Projects/astyle/test

# display help
# $exedir/astyle -h

# update the test directory
mkdir  --parents $testdir
mkdir  --parents $testdir/recurse

#copy files to the test directory
cp  --preserve $srcdir/*.cpp   $testdir
cp  --preserve $srcdir/*.h     $testdir
cp  --preserve $srcdir/*.cpp   $testdir/recurse
cp  --preserve $srcdir/*.h     $testdir/recurse

# opts=" --style=k&r "

$exedir/astyle  --style="k&r"  "$testdir/*.cpp"  "$testdir/*.h"
# $exedir/astyle  $opts  "$HOME/CodeBlocks/*.cpp"  "$HOME/CodeBlocks/*.h"

echo
read -sn1 -p "Press Enter to end . . ."
