#!/usr/bin/perl -w

# Add this file in your CVSROOT. Add the following line 
# to the checkoutlist file in your CVSROOT
# indent_commit.pl Failed to checkout indent_commit.pl
# Add the following line (substitute <module_name> with the 
# module that should be formatted) to your commitinfo file.
# <module_name>$CVSROOT/CVSROOT/indent_commit.pl
# Remember that your local code will only be updated with the 
# server indented code if you checkout a new version from the 
# server or release and recheckout your code.


$beautifier = '/user/local/bin/astyle';
$suffix = '.orig';

LOOP: foreach $_
(@ARGV) {
    chomp;
    next LOOP unless -f $_ && -T $_;
    $copy = $_ . $suffix;

    print "processing $_ \n";
    if (/.+\.cpp$/ || /.+\.CPP$/) {
        @args = ("$beautifier","--style=ansi","$_");
        goto PROCESS;
    }
    if
    (/.+\.h$/ || /.+\.H$/) {
        @args = ("$beautifier","--style=ansi","$_");
        goto PROCESS;
    }
    if (/.+\.c$/ || /.+\.C$/)
    {
        @args = ("$beautifier","--style=ansi","$_");
        goto PROCESS;

    }
    if (/.+\.java$/ || /.+\.JAVA$/) {
        @args= ("$beautifier", "--style=java","$_");
        goto PROCESS;
    }
    next LOOP;

PROCESS:

    print "formatting $_ \n";
    system(@args) == 0 or die $@;
    unlink $copy or die $@;
}
