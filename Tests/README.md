# Guide To Automated Testing

***!IMPORTANT! All of your code should be written in the root directory,
and you run the test from the /Tests directory***
## Running Basic Tests
To run tests, you need a file to test call it to_test.cpp.
Then, populate the Input folder with your test cases.
Then you can run
```bash
./run.sh to_test
```

You also need results to compare it to. You can either populate the
Output folder, or create another file validator.cpp which generates correct answers
```bash
./run.sh to_test
./run.sh to_test validator 
```

## Using a checker to run tests
Sometimes, rather than compare outputs, it's better to check that an output
is correct. Make a script checker.cpp that takes as input a string - the name of the
input/output file to test, and outputs any errors found. Then to run it on
all test cases:
```bash
./check.sh to_test check
```

## Generating Tests
If you want to run on a bunch of test cases, you will need a generator
of test cases, generator.cpp. You can just generate `K` test cases with no output:
```bash
./gen.sh generator K
./run.sh to_test
```
Usually, though, the generator will also need to have some way of generating output.
If you have a validator, then you can run the validator on each input file to get the output.
```bash
./gen.sh generator K validator
```

Sometimes, it is preferable to make a single file that creates
both the desired input and output for a problem.
Such a file, named test_generator.cpp, should send the input to
stdout and the desired output to stderr. Then run:
```bash
./gen_pair.sh test_generator K
./run.sh to_test
```

## Creating random tests
***Your test case generators will get an integer seed from `1` to `K` as
input from standard input, so you can call `srand(seed);` and use `rand()` to ensure that
your test cases are different.***

### Bonus
To clear all the folders:
```bash
./clear.sh
```
To clear and also add n empty files for sample input/output
```bash
./clear.sh n
```


# Debugging
If you get permission denied error when trying to run stuff, try marking the files as executable

```
/Tests$ chmod +x ./*.sh
```