#!/bin/bash
#
# Build script for c-4
#

# Create build directory
mkdir build

# Compile source
cd build
cmake ..
make -j 2

