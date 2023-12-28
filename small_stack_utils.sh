#!/bin/bash

NUMBERS=$(seq 0 99 | sort -R | tr '\n' ' ')
././bin/push_swap $NUMBERS
