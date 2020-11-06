#!/bin/bash

differences=0
cd test
for outputfile in good_outputs/*.txt
do
	difference=`diff -U 0 $"${outputfile//good_}" $outputfile | grep ^@ | wc -l`
	differences+=$difference
done

exit $differences
