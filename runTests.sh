#!/bin/bash
#cmake -S . -B build
# the above line is not needed for running tests
cmake --build build && cd build && ctest