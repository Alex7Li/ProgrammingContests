#!/bin/bash
c++ -o gen ../$1.cpp
mv gen gen.exe 2>/dev/null; true
n=${2-10}
# For i from 1 to the 3rd arg, or 10
for ((i=1; i <= $n; i++))
do
  A="./Input/gen${i}.in"
  B="./Output/gen${i}.ans"
  echo "Generating file ${A}"

  echo $i | ./gen.exe > $A 2> $B
done
rm -f gen.exe

