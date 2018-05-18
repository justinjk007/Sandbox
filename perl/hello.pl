#!/usr/bin/perl

# Strict and warnings are recommended.
use strict;
use warnings;
use Term::ANSIColor;

print "Hello, World!\n";
my $foo = "this should be colored";
print colored(sprintf("%s %s", '01234.56789', $foo), 'blue'), "\n";
print "This should not be colored\n";
