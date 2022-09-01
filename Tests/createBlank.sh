#!/bin/bash
if [ $# -eq 1 ]; then
  for ((i=1; i <= $1; i++))
  do
    A="Input/test${i}.in"
    B="Output/test${i}.ans"
    touch $A
    touch $B
  done
fi
