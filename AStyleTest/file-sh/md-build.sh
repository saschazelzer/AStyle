#!/bin/bash
# compile MonoDevelop

# load library file
if [ -f libTYSP.sh ]; then source libTYSP.sh
else  source $HOME/bin/libTYSP.sh
fi

projdir=$HOME/Projects/TestData/MonoDevelop

# check for correct hostname
if [ $HOSTNAME != "ubuntu" ]; then
	echo "Cannot compile MonoDevelop on host \"$HOSTNAME\""
	exit 1
fi

#define variables here
result=:
unset result

cd $projdir

# do this if not a makefile or if it is requested
askconfig=yes
if [ ! -f Makefile ] || [ $askconfig == yes ]; then
	echo
	echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	echo "*                              running configure                              *"
	echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	if [ ! -f Makefile ]; then
		YESNO="y"
	else
		promptYESNO  "Do you want to rebuild the Makefile" "n"
	fi

	# default prefix is /usr/local
	if [ ! $YESNO ] || [ $YESNO = "y" ]; then
        sh configure
    fi

	result=$?; echo ; echo RESULT=$result
	if [ $result -ne 0 ] && [ $result -ne 100 ]; then  read -sn1 -p "Error running config! "; fi
	unset result
	unset YESNO
fi

echo
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
echo "*                             compiling monodevelop                              *"
echo "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
TIMEFORMAT=$'\nreal\t%0lR'
time  make

result=$?; echo ; echo RESULT=$result
if [ $result -ne 0 ] && [ $result -ne 100 ]; then  read -sn1 -p "Error running make! "; echo; exit; fi
unset result

echo
read -sn1 -p "Press Enter to end . . ."
