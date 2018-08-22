#!/usr/bin/env python2.7

import re # regex module

foo = "               size      inuse       free        pin    virtual "
foo += "memory      8388496    7300693    1087803    1734437    2099161 "
foo +="pg space    4259840     137305 "

regex_output = re.search('memory\s+(\d*\.\d+|\d+)\s+(\d*\.\d+|\d+)\s+(\d*\.\d+|\d+)', foo) # search for the regex in foo varaible

print "size: " + regex_output.group(1)
print "inuse: " + regex_output.group(2)
print "free: " + regex_output.group(3)
