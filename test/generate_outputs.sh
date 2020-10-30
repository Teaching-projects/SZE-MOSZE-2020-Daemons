#!/bin/bash
touch test/outputs.txt
declare -a files

for filename in test/units/*.json; do
	files+=(`echo $filename | grep -o -P '(?<=units/).*(?=.json)'`)
done

fileCount=${#files[@]}

for ((c=0;c<$((fileCount-1));c++))
do
	for ((i=$c;i<$((fileCount-1));i++))
	do
		echo `./runMain test/units/${files[$((i+1))]}.json test/units/${files[$c]}.json` >> test/outputs.txt
		echo `./runMain test/units/${files[$c]}.json test/units/${files[$((i+1))]}.json` >> test/outputs.txt
	done
done
