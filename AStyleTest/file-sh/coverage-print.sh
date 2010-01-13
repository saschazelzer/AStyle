#!/bin/bash
# Run gcov to print the coverage report
# AStylec must be run to create the *.gcno files

# this is the source file to display
filename=ASFormatter

cd  ../build/cb-gcc/objc/AStyle/src

# check for the graph file created by the compile
if [ ! -f $filename.gcno ]; then
echo Must compile astylec to create the .gcno graph files!
read -sn1 -p "Press Enter to end . . ."
exit 100
fi

# check for the data file created by running the program
if [ ! -f $filename.gcda ]; then
echo Must run astylec to create the .gcda data files!
read -sn1 -p "Press Enter to end . . ."
exit 100
fi

# use the source file name to print the report
gcov  $filename

# open the coverage file in SciTE
scite  $filename.cpp.gcov


echo
echo end of gcov
echo
read -sn1 -p "Press Enter to end . . ."
