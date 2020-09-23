#!/bin/bash

differences=0

for outputfile in outputs/*.txt
do
	otherdiffs=$(diff $"good_outputs${outputfile//outputs}" $outputfile)
	differences=$((differences+otherdiffs))
done

exit $differences
