#!/bin/bash
set -e

if [ -f "count.cpp" ]; then
    g++ -std=c++17 count.cpp -o count 
    ./count command.log
else
    echo "No source file found!"
    exit 1
fi