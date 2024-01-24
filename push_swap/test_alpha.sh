#!/bin/bash
#ARG=$(echo -e "\n")

PROGRAM_NAME="$1"

I=0
MESS="Questi casi devono stampare Error"
echo -e "\033[1;33m$MESS\033[0m"

MESS=" = input 'a'"
ARG="a"
((I++)) #1
echo -e "\033[1;31m$I$MESS$?\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'a a'"
ARG="a a"
((I++)) #2
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'a a a'"
ARG="a a a"
((I++)) #3
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '1a'"
ARG="1a"
((I++)) #4
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '1 a'"
ARG="1 a"
((I++)) #5
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '2 1 a'"
ARG="2 1 a"
((I++)) #6
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '2 1 3 a'"
ARG="2 1 3 a"
((I++)) #7
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '3 1 2 5 7a'"
ARG="3 1 2 5 7a"
((I++)) #8
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '3 1 2 a5 7'"
ARG="3 1 2 a5 7"
((I++)) #9
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '-'"
ARG="-"
((I++)) #10
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '+'"
ARG="-"
((I++)) #11
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '--'"
ARG="-"
((I++)) #12
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '++'"
ARG="-"
((I++)) #13
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '-+'"
ARG="-"
((I++)) #14
echo -e "\033[1;31m$I$MESS\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"
