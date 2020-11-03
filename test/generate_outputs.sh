#!/bin/bash
touch test/outputs.txt
declare -a files


fileCount=${#files[@]}

for ((c=0;c<$((fileCount-1));c++))
do
	for ((i=$c;i<$((fileCount-1));i++))
	do
		echo `./runMain scenario1.json` >> test/outputs.txt
		echo `./runMain scenario1.json` >> test/outputs.txt
	done
done
