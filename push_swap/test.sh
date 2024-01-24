#!/bin/bash

PROGRAM_NAME="$1"

clear
./test_int.sh "$PROGRAM_NAME"
./test_alpha.sh "$PROGRAM_NAME"
./test_space.sh "$PROGRAM_NAME"