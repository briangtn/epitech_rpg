#!/bin/bash

id=1
scene=1
column=1
line=1
if [ -z $1 ]
then
	echo "Please enter a filename"
elif [ -e $1 ]
then
	echo "File $1 already exists!"
else
	echo NB_SCENE : \"$2\" >> $1
	echo TILE_PER_SCENE \(COL x LINES\) : \"$3\" x \"$4\" >> $1
	while [ $scene -le $2 ]
	do
		echo >> $1
		echo SCENE $scene: >> $1
		while [ $column -lt $3 ]
		do
			while [ $line -lt $4 ]
			do
				echo TILE_ID : \"$id\" \; TILE_POS : \"$column\" x \"$line\" \; EVENT_ID : \"1\" \; TILE_TYPE : \"1\" \; LAYER : \"1\" >> $1
				((line++))
				((id++))
			done
			((column++))
			line=1
		done
		((scene++))
		line=1
		column=1
	done
fi