#!/bin/bash
set -e

if [ -f "cv_1.cpp" ]; then
    g++ -std=c++17 cv_1.cpp -o cv_1 `pkg-config --cflags --libs opencv4`
    ./cv_1 test_red_armor.jpg
else
    echo "No source file found!"
    exit 1
fi