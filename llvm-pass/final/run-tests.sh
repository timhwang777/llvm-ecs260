#!/bin/bash

LLVM_DIR="$HOME/llvm-3.8"
test_dir="tests"

### Compiling and linking source code to apply instrument pass
$LLVM_DIR/bin/clang -emit-llvm -c check_bounds.c -o check_bounds.bc

echo -e "\nInstrumenting Code------------------------------------------"
for test in $test_dir/test*.c; do
  test=`echo $test | cut -d . -f 1`
  $LLVM_DIR/bin/clang -g -c -emit-llvm $test.c -o $test.bc
  $LLVM_DIR/bin/llvm-link -o ${test}_temp.bc $test.bc check_bounds.bc

  echo -e "Test: $test.c\n"
  $LLVM_DIR/bin/opt -load ./Passes.so -instrument ${test}_temp.bc > ${test}_i.bc
done
echo "Done Instrumenting Code-------------------------------------"


### Running instrumented tests
echo -e "\nRunning Tests-------------------------------------------------"
for test in $test_dir/test*.c; do
  test=`echo $test | cut -d . -f 1`
  #echo -e "Test: $test.c\n"
  $LLVM_DIR/bin/lli ${test}_i.bc
done
echo -e "Done Running Tests--------------------------------------------"
