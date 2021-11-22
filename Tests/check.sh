#!/bin/bash
# run inputs and compare them
./save.sh $1 $2

cd Input
for filename in *; do
  O="../CodeOutputs/${filename}"
  echo "Running file " $filename
  # Generate the output
  ../alg1.exe < $filename > $O
  # Check the output
  result_file="../CodeOutputs/checker_${filename}"
  echo $filename | ../alg2.exe > $result_file
  cat $result_file
done
cd ..

rm -f alg1.exe
rm -f alg2.exe
echo "done"
read
