#!/bin/bash

differences=0

for outputfile in outputs/*.txt
do
	#echo $"good_outputs${outputfile//outputs}"
	otherdiffs=$(diff $"good_outputs${outputfile//outputs}" $outputfile)
	differences=$((differences+otherdiffs))
done

exit $differences
