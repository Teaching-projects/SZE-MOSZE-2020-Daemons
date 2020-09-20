#!/bin/bash

declare -a goodfiles
declare -a outputfiles

for filename in good_outputs/*.txt; do
	goodfiles+=($filename)
done

for filename in outputs/*.txt; do
	outputfiles+=($filename)

differences=0

for goodfile in goodfiles
do
	for outputfile in outputfiles
	do
		differences+=`diff goodfile outputfile`
	done
done

return differences
