#!/bin/bash

differences=0
cd test
for outputfile in good_outputs/*.txt
do
	otherdiffs=`diff $"${outputfile//good_}" $outputfile`
	differences+=$otherdiffs
done

exit $differences