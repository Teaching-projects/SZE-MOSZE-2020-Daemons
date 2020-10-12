#!/bin/bash
g++ -Wall -std=c++17 *.cpp &>> output.txt
cppcheck *.cpp --enable=warning &>> output.txt
if [ -s output.txt ]
then
        cat output.txt
        exit 1
fi
rm output.txt

