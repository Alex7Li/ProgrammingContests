#!/bin/bash
c++ -o gen ../$1.cpp
n=${2-10}
if [ $# -eq 3 ]; then
  c++ -o alg ../$3.cpp
fi
# For i from 1 to the 2rd arg, or 10
for ((i=1; i <= $n; i++))
do
  A="Input/gen${i}.txt"
  echo "Generating file ${A}"
  echo $i | ./gen.exe > $A

  if [ $# -eq 3 ]; then
    B="Output/gen${i}.txt"
    ./alg2.exe < $A > $B
  fi
done
rm -f gen.exe
if [ $# -eq 3 ]; then
  rm -f alg.exe
fi
