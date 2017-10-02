#!/bin/bash
TITLE="System Information for $HOSTNAME"
# this is a test
# printf "The shell is %s ........ %s\n" "$SHELL" "$TITLE"

# For "read" command "-e" flag reads the whole line as string
# "-a" flag reads the whole line as an array of strings separated by spaces

echo "Enter a sample input:"
read -e sample_text
echo "Enter substring to search:"
read -e sub_string

echo "Number of occurrences of \"$sub_string\" in \"sample_text\" is "
echo "$sample_text" | grep -o "$sub_string" | wc -l
