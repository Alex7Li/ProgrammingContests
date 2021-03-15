#!/bin/bash
c++ -o gen ../$1.cpp
n=${2-10}
# For i from 1 to the 3rd arg, or 10
for ((i=1; i <= $n; i++))
do
  A="./Input/gen${i}.txt"
  B="./Output/gen${i}.txt"
  echo "Generating file ${A}"

  echo $i | ./gen.exe > $A 2> $B
done
rm -f gen.exe

