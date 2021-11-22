#!/bin/bash
# Compile the inputs and run them
rm -f alg1.exe
rm -f alg2.exe
c++ -o alg1 ../$1.cpp
# If there are 2 arguments, compile both inputs
if [ $# -eq 2 ]; then
  c++ -o alg2 ../$2.cpp
fi
