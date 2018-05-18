#!/usr/bin/perl

# Strict and warnings are recommended.
use strict;
use warnings;

my $argc = @ARGV;


if ($argc != 0) {
    print "argc is $argc\n";
    my $name   = $ARGV[0];
    if($name eq "test" || $name eq "te")
    {
	print "This is a test\n";
    }
}
else{
    print "no args\n";
}
