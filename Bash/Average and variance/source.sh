#Jan Skwarczek
#!/bin/bash
	n=0
	sum=0
	war=0
	sr=0
	tab=()
	while read line
	do
		if [ "$line" != "" ]
		then
			tab[$n]=$line
			let sum=sum+line
			((n++))
		fi
		done
		sr=$((sum/n))
		echo $sr
		for i in "${tab[@]}"
		do
		temp=$(((i-sr)*(i-sr)))
		let war=war+temp
	done
echo $((war/n))