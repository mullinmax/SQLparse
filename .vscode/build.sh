#!/bin/bash
rm SQLparse > /dev/null
g++ -Wall -std=c++11 -O3 main.cpp -o SQLparse 