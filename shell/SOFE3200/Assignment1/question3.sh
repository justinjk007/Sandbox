#!/bin/bash

# This script implements a mini multiple choice game


#Get username and beautify it
current_user="$(tr '[:lower:]' '[:upper:]' <<< ${USER:0:1})${USER:1}"

mark=0

question1="What is the best Editor/IDE in the whole universe ?"
q1_option1="Gnu Emacs"
q1_option2="Emacs"
q1_ans="1"

question2="What is the best Editor/IDE in the whole universe ?"
q2_option1="Gnu Emacs"
q2_option2="Emacs"
q2_ans="1"

question3="What is the best Editor/IDE in the whole universe ?"
q3_option1="Gnu Emacs"
q3_option2="Emacs"
q3_ans="1"

question4="What is the best Editor/IDE in the whole universe ?"
q4_option1="Gnu Emacs"
q4_option2="Emacs"
q4_ans="1"

question5="What is the best Editor/IDE in the whole universe ?"
q5_option1="Gnu Emacs"
q5_option2="Emacs"
q5_ans="1"

echo "Hello $current_user, Welcome to the quiz"
echo "To select answers, Exactly enter only the option number when prompted"

echo $question1
echo "   [1] $q1_option1     [2] $q1_option2 "
read -e input
if [ "$input" = "$q1_ans" ]; then
    let "mark += 1"
fi

echo $question2
echo "   [1] $q2_option1     [2] $q2_option2 "
read -e input
if [ "$input" = "$q1_ans" ]; then
    let "mark += 1"
fi

echo $question3
echo "   [1] $q3_option1     [2] $q3_option2 "
read -e input
if [ "$input" = "$q1_ans" ]; then
    let "mark += 1"
fi

echo $question4
echo "   [1] $q4_option1     [2] $q4_option2 "
read -e input
if [ "$input" = "$q1_ans" ]; then
    let "mark += 1"
fi

echo $question5
echo "   [1] $q5_option1     [2] $q5_option2 "
read -e input
if [ "$input" = "$q1_ans" ]; then
    let "mark += 1"
fi

echo "Thanks for completing the quiz your final mark is $mark"
