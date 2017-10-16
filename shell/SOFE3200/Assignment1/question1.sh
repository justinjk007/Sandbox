#!/bin/bash

# This script takes in some sample text and a substring and then
# outputs the number of times the substring exists in the main string.

# Get the input from the user
echo "Enter a sample input:"
read -e sample_text
echo "Enter substring to search:"
read -e sub_string

# Use grep to search for the substring, -o option is used return only
# matching lines Then pipe the output of grep into wc, the -l flag is
# used to output only line count which is the same as the number of
# times the substring appeared in the sample text.
ans=$(echo "$sample_text" | grep -o "$sub_string" | wc -l)

echo "Number of occurrences of \"$sub_string\" in \"$sample_text\" is $ans"
