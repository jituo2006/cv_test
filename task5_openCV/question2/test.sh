#!/bin/bash
set -e

if [ -f "cv_2.cpp" ]; then
    g++ -std=c++17 cv_2.cpp -o cv_2 `pkg-config --cflags --libs opencv4`
    ./cv_2 test_rune.png
else
    echo "No source file found!"
    exit 1
fi