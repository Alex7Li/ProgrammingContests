#!/bin/bash
rm -rf CodeOutputs
rm -rf Input
rm -rf Output
mkdir CodeOutputs
mkdir Input
mkdir Output
if [ $# -eq 1 ]; then
  for ((i=1; i <= $1; i++))
  do
    A="Input/sample${i}.txt"
    B="Output/sample${i}.txt"
    touch $A
    touch $B
  done
fi
