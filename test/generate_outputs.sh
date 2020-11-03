#!/bin/bash

echo `./a.out scenario1.json` >> test/outputs.txt
echo `./a.out scenario2.json` >> test/outputs.txt

diff test/outputs.txt test/good_outputs.txt