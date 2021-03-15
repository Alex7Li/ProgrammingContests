#!/bin/bash
# run inputs and compare them
if [ $# -eq 1 ]; then
  ./save.sh $1
else
  ./save.sh $1 $2
fi
cd Input
for filename in *; do
  echo "Running on file " $filename
  O="../CodeOutputs/${filename}"
  ../alg1.exe < $filename > $O

  outFile="../Output/${filename}"

  if [ $# -eq 2 ]; then
    ../alg2.exe < $filename > $outFile
  fi

  diff $O $outFile
done
rm -f myout.txt
rm -f trueout.txt
cd ..
rm -f alg1.exe
rm -f alg2.exe
echo "done"
read
