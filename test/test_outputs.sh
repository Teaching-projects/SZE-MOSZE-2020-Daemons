#!/bin/bash

differences=0
cd test
for outputfile in outputs/*.txt
do
	otherdiffs=`diff $"good_outputs${outputfile//outputs}" $outputfile`
	differences=+$otherdiffs
	
done

exit $differences
