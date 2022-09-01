#!/bin/bash
# Compile the inputs and run them
rm -f alg1.exe
rm -f alg2.exe
c++ -o alg1 ../$1.cpp
 # System dependent, sometimes alg1.exe and sometimes just alg1 is made
mv alg1 alg1.exe 2>/dev/null; true
# If there are 2 arguments, compile both inputs
if [ $# -eq 2 ]; then
  c++ -o alg2 ../$2.cpp
  mv alg2 alg2.exe 2>/dev/null; true
fi
