#!/usr/bin/perl

# Strict and warnings are recommended.
use strict;
use warnings;

print "\nTesting search\n";
my $foo = "habahabahbah \nthis\nabc\n";
if($foo =~ m/this\nabc\n$/){
    print "This is true\n";
}
else{
    print "This is false\n";
}

print "\nTesting search\n";
$foo = "habahabahbah \nthis\nis a test\n";
if($foo =~ m/is a test$/){
    print "This is true\n";
}
else{
    print "This is false\n";
}

print "\nTesting String matching\n";
$foo = "
Garbage directory
/test/this/is/a/directory
/this/is/another/foo\nThisd is is\nDrop stuff testing\nRandom stuff emacs is great";
$foo =~ /^\/test.*$/;
print "Drop in:\n$foo\n";
