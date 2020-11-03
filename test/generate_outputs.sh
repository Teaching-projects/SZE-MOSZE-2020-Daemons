#!/bin/bash

echo `./runMain scenario1.json` >> test/outputs.txt
echo `./runMain scenario2.json` >> test/outputs.txt

diff test/outputs.txt test/good_outputs.txt