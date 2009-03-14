#! /usr/bin/perl -w
use strict;

my $astyle = "/usr/bin/astyle";
my $text;
{
    local $/;
    $text = <>;
}

open(ASTYLE, "|$astyle");
print ASTYLE $text;
close(ASTYLE);
