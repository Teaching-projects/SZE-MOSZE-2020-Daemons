#!/bin/bash
g++ -Wall -std=c++17 *.cpp &> output.txt
if [ -s output.txt ]
then
        exit 1
fi
