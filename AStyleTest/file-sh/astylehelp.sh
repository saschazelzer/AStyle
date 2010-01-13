# test the astyle console help display
# change the $exedir as needed

exedir=$HOME/astyle/bin
#exedir=$HOME/astyle/_cb-gcc/bin
#exedir=$HOME/astyle/_cb-intel/bin

# display help
$exedir/astyle -h

echo
read -sn1 -p "Press Enter to end . . ."
