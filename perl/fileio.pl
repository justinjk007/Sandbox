#!/usr/bin/perl

# Strict and warnings are recommended.
use strict;
use warnings;

# Define a hashtable
my %hash_table = (
    "apple"  => "red",
    "orange" => "orange",
    "grape"  => "purple",
    );


my $filename = 'test.txt';
open(my $fh, '>', $filename) or die "Could not open file '$filename' $!";
print $fh "Contents of the hashtable\n\n";
for my $fruit (keys %hash_table) {
    print $fh "The color of '$fruit' is $hash_table{$fruit}\n";
}
close $fh;
