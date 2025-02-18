#!/bin/bash
#
# Build script for C-4 (cfour)
#

# Create build directory
mkdir build

# Compile source
cd build
cmake ..
make -j 2

# Test code
make test
