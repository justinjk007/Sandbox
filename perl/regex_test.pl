#!/usr/bin/perl

# Strict and warnings are recommended.
use strict;
use warnings;

my $foo = "habahabahbah \nthis\nabc\n";
if($foo =~ m/this\nabc\n$/){
    print "This is true\n";
}
else{
    print "This is false\n";
}

$foo = "habahabahbah \nthis\nis a test\n";
if($foo =~ m/is a test$/){
    print "This is true\n";
}
else{
    print "This is false\n";
}
