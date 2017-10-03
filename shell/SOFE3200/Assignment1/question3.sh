#!/bin/bash

# This script implements a mini multiple choice game

#Get username and beautify it
current_user="$(tr '[:lower:]' '[:upper:]' <<< ${USER:0:1})${USER:1}"

RED='\033[0;31m' # Define color red
CYAN='\033[0;36m' # Define color cyan
GREEN='\033[0;32m' # Define color green
PURPLE='\033[0;35m' # Define color purple
NC='\033[0m'	 # No Color

mark=0

# Define all the questions and the answers
question1="What is the best Editor/IDE in the whole universe ?"
q1_option1="Gnu Emacs"
q1_option2="Emacs"
q1_ans="1"
question2="Who wrote the C++ programming language ?"
q2_option1="Dennis Richie"
q2_option2="Bjarne Stroustrup"
q2_ans="2"
question3="What is the worst browser to ever exist ?"
q3_option1="Microsoft Internet Explorer"
q3_option2="Microsoft Edge"
q3_ans="1"
question4="Will valve ever make Half-life 3 ?"
q4_option1="No"
q4_option2="Maybe (Hopefully)"
q4_ans="2"
question5="Is the system broken ?"
q5_option1="No"
q5_option2="Yes"
q5_ans="1"

# Greet the user and explain whats happening
echo
echo -e "Hello ${PURPLE}$current_user${NC}, Welcome to the quiz"
# "-e" flag is used in echo to enable character escaping
echo "To select answers, Exactly enter only the option number when prompted"
echo

# Starts asking the questions, the answers are checked as soon as they
# are entered and the mark is implemented accordingly
echo $question1
echo -e "   ${CYAN}[1]${NC} $q1_option1     ${CYAN}[2]${NC} $q1_option2 "
read -e input
if [ "$input" = "$q1_ans" ]; then
    let "mark += 1"
fi
echo $question2
echo -e "   ${CYAN}[1]${NC} $q2_option1     ${CYAN}[2]${NC} $q2_option2 "
read -e input
if [ "$input" = "$q2_ans" ]; then
    let "mark += 1"
fi
echo $question3
echo -e "   ${CYAN}[1]${NC} $q3_option1     ${CYAN}[2]${NC} $q3_option2 "
read -e input
if [ "$input" = "$q3_ans" ]; then
    let "mark += 1"
fi
echo $question4
echo -e "   ${CYAN}[1]${NC} $q4_option1     ${CYAN}[2]${NC} $q4_option2 "
read -e input
if [ "$input" = "$q4_ans" ]; then
    let "mark += 1"
fi
echo $question5
echo -e "   ${CYAN}[1]${NC} $q5_option1     ${CYAN}[2]${NC} $q5_option2 "
read -e input
if [ "$input" = "$q5_ans" ]; then
    let "mark += 1"
fi

echo
echo -e "Thanks for completing the quiz your final mark is ${GREEN}$mark${NC}"

# TODO Mail the marks to root
