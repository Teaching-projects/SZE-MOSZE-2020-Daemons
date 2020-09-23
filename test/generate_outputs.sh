#!/bin/bash
cd ..
declare -a files

for filename in test/units/*.json; do
	files+=(`echo $filename | grep -o -P '(?<=units/).*(?=.json)'`)
done

fileCount=${#files[@]}

for ((c=0;c<$((fileCount-1));c++))
do
	for ((i=$c;i<$((fileCount-1));i++))
	do
		rm test/outputs/${files[$((i+1))]}-${files[$c]}.txt
		touch test/outputs/${files[$((i+1))]}-${files[$c]}.txt
		echo `./a.out test/units/${files[$((i+1))]}.json test/units/${files[$c]}.json` >> test/outputs/${files[$((i+1))]}-${files[$c]}.txt
		rm test/outputs/${files[$c]}-${files[$((i+1))]}.txt
		touch test/outputs/${files[$c]}-${files[$((i+1))]}.txt
		echo `./a.out test/units/${files[$c]}.json test/units/${files[$((i+1))]}.json` >> test/outputs/${files[$c]}-${files[$((i+1))]}.txt
	done
done
