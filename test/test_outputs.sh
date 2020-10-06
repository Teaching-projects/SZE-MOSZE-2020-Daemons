#!/bin/bash

differences=0
cd test
for outputfile in good_outputs/*.txt
do
	echo "`diff $"${outputfile//good_}" $outputfile`"
	diff $"${outputfile//good_}" $outputfile > /dev/null 2>&1
	differences+=$?
done

exit $differences
