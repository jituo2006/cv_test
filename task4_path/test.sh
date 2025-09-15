#!/bin/bash
set -e

if [ -f "findPath.cpp" ]; then
    g++ -std=c++17 findPath.cpp bfs.cpp -o findPath
    ./findPath 0 0 2 3
else
    echo "No source file found!"
    exit 1
fi