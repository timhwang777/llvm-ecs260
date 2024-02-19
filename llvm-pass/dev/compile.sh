#!/bin/bash

LLVM_DIR="$HOME/llvm-3.8"
test_dir="tests"
 
### Cleaning up
rm -f *.so *.os *.bc
rm -f $test_dir/*.bc

### Compiling LLVM pass
g++ -o Instrument.os -c -Wall -std=c++11 -Wformat=2 -Wextra -Werror -O3 -fomit-frame-pointer -fno-exceptions -fno-rtti -fPIC -Woverloaded-virtual -Wcast-qual -fPIC -DNDEBUG -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -isystem $LLVM_DIR/include Instrument.cpp


### Creating shared library
g++ -o Passes.so -Wall -std=c++11 -Wformat=2 -Wextra -Werror -shared Instrument.os -L $LLVM_DIR/lib -lpthread -ldl -lm 
