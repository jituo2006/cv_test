#!/bin/bash
set -e

if [ -f "main.cpp" ]; then
    g++ main.cpp -o main
    ./main
else
    echo "No source file found!"
    exit 1
fi