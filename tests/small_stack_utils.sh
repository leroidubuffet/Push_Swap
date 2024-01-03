#!/bin/bash

NUMBERS=$(seq -999 999 | sort -R | tr '\n' ' ')
././bin/push_swap $NUMBERS
# | ./checker_Mac $NUMBERS
