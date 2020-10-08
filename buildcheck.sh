#!/bin/bash
g++ -Wall -std=c++17 *.cpp &> output.txt
if [ -s output.txt ]
then
        cat output.txt
        exit 1
fi
