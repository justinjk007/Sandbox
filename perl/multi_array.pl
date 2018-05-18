#!/usr/bin/perl

my @foo = (
    ['e11', 'e12' ],
    ['e21', 'e22' ],
    );

foreach my $fooArray (@foo)
{
    foreach my $fooCell (@$fooArray)
     {
	 print "$fooCell\n";
     }
}
