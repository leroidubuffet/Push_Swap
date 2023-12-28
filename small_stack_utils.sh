#!/bin/bash

NUMBERS=$(seq -999 999 | sort -R | tr '\n' ' ')
./push_swap $NUMBERS | ./checker_Mac $NUMBERS
