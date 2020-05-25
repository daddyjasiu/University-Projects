#Jan Skwarczek
#!/bin/bash

checkPerm(){

	perm=0

	if [[ $1 == "---" ]]
	then
		perm=0

	elif [[ $1 == "--x" ]]
	then
		perm=1

	elif [[ $1 == "-w-" ]]
	then
		perm=2

	elif [[ $1 == "-wx" ]]
	then
		perm=3

	elif [[ $1 == "r--" ]]
	then
		perm=4


	elif [[ $1 == "r-x" ]]
	then
		perm=5

	elif [[ $1 == "rw-" ]]
	then
		perm=6

	elif [[ $1 == "rwx" ]]
	then
		perm=7

	fi
}

	read line
	i=1
	
	while read line a b c d e f g nazwa
	do

		isFolder="${line:0:1}"
		perm1="${line:1:3}"
		checkPerm $perm1

		isExe="${line:3:1}"

		output="${perm}"

		perm2="${line:4:3}"
		checkPerm $perm2

		temp="${output}"
		output="${temp}${perm}"

		perm3="${line:7:3}"
		checkPerm $perm3

		temp="${output}"
		output="${temp}${perm}"

		if [[ $isFolder == "d" ]]
		then
		echo $nazwa"/ "$output
		elif [[ $isExe == "x" ]]
		then
		echo $nazwa"* "$output
		else
		echo $nazwa $output
		fi

		i=$((i+1))
	done
