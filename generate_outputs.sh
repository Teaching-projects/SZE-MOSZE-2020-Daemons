#!/bin/bash

declare -a files

for filename in units/*.json; do
	files+=(`echo $filename | grep -o -P '(?<=units/).*(?=.json)'`)
done

fileCount=${#files[@]}

for ((c=0;c<$((fileCount-1));c++))
do
	for ((i=$c;i<$((fileCount-1));i++))
	do
		rm outputs/${files[$((i+1))]}-${files[$c]}.txt
		touch outputs/${files[$((i+1))]}-${files[$c]}.txt
		echo `./a.out units/${files[$((i+1))]}.json units/${files[$c]}.json` >> outputs/${files[$((i+1))]}-${files[$c]}.txt
		rm outputs/${files[$c]}-${files[$((i+1))]}.txt
		touch outputs/${files[$c]}-${files[$((i+1))]}.txt
		echo `./a.out units/${files[$c]}.json units/${files[$((i+1))]}.json` >> outputs/${files[$c]}-${files[$((i+1))]}.txt
	done
done
