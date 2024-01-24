#!/bin/bash
#ARG=$(echo -e "\n")

PROGRAM_NAME="$1"

I=0
MESS="Questi casi non devono stampare Error"
echo -e "\033[1;33m$MESS\033[0m"

MESS=" = input '0'"
ARG="0"
((I++)) #1
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '0 1'"
ARG="0 1"
((I++)) #2
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '0 1 2'"
ARG="0 1 2"
((I++)) #3
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '0 1 2 3'"
ARG="0 1 2 3"
((I++)) #4
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '0 1 2 3 4'"
ARG="0 1 2 3 4"
((I++)) #5
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '-5 -4 -3 -2 -1 0 +1 +2 +3 +4 +5'"
ARG="-5 -4 -3 -2 -1 0 +1 +2 +3 +4 +5"
((I++)) #6
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '3 1 2'"
ARG="3 1 2"
((I++)) #7
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input '+5634 2 -64 8'"
ARG="+5634 2 -64 8"
((I++)) #8
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'MAX_INT MIN_INT'"
ARG="+2147483647 -2147483648"
((I++)) #9
(
	echo -e "\033[1;32m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
) & PID=$!
exit_code=${PIPESTATUS[0]}
if [ "$PROGRAM_NAME" = "checker" ]; then
	sleep 1
	if ps -p $PID > /dev/null; then
       kill $PID 2>/dev/null
    fi
fi
wait $PID
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

#-----------------------------------------------------------------------------
MESS="Questi casi devono stampare Error"
echo -e "\033[1;33m$MESS\033[0m"

MESS=" = input 'MAX_INT+1 MIN_INT'"
ARG="+2147483648 -2147483648"
((I++)) #10
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'MAX_INT MIN_INT-1'"
ARG="+2147483647 -2147483649"
((I++)) #11
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'positive int out of range'"
ARG="+21474836471 -2147483648"
((I++)) #12
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'negative int out of range'"
ARG="+2147483647 -21474836481"
((I++)) #13
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'extra long number'"
ARG="1 2 3 4 55555555555555555555555555555555555555555555 6 7 8"
((I++)) #14
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'duplicate'"
ARG="1 6 7 8 1"
((I++)) #15
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'duplicate'"
ARG="8 7 1 0 +1"
((I++)) #16
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'duplicate'"
ARG="8 7 +1 0 +1"
((I++)) #17
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'duplicate'"
ARG="8 7 1 +0 +3 0"
((I++)) #18
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'duplicate'"
ARG="8 7 +1 0 +3 -0"
((I++)) #19
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'duplicate'"
ARG="8 7 +1 +0 +3 -0"
((I++)) #20
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'doppio segno'"
ARG="8 7 1 +0 ++3 12"
((I++)) #21
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'doppio segno'"
ARG="8 7 +1 0 +3 --12"
((I++)) #22
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"

MESS=" = input 'doppio segno'"
ARG="8 7 +-1 +0 +3 -12"
((I++)) #23
echo -e "\033[1;31m$I$MESS!\033[0m" && valgrind --leak-check=full --show-leak-kinds=all -s ./$PROGRAM_NAME "$ARG" 2>&1 | grep -E "LEAK SUMMARY|ERROR SUMMARY|Error" | grep -v 'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)'
exit_code=${PIPESTATUS[0]}
echo -e "$PROGRAM_NAME exit status: $exit_code\n"
