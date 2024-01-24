#!/bin/bash
#ARG=$(echo -e "\n")

PROGRAM_NAME="$1"

I=0
MESS="Questi casi controllano la presenza di spazi nell input. Sono errori da gestire? Non lo so, ma io l'ho fatto"
echo -e "\033[1;33m$MESS\033[0m"

MESS=" = input '\n'"
ARG="
"
((I++)) #1
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input con spazio iniziale"
ARG=" 1 4 7 9 15"
((I++)) #2
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input spazio finale"
ARG="1 4 7 9 15 "
((I++)) #3
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input doppio spazio nel mezzo"
ARG="1 4 7  9 15"
((I++)) #4
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input con spazio tra segno e numero"
ARG="1 4 7 + 9 15"
((I++)) #5
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"
