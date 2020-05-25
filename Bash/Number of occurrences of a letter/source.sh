#Jan Skwarczek
#!/bin/bash
read znakL
znak=${znakL:$i:1}
while read line
do

	if [[ $znakL =~ "=" ]]
	then
		y="${line//[^$znak]}"
		echo "${#y}"

		else
		char=${znak^}
		z="${line//[^$char]}"
		y="${line//[^$znak]}"
		a="${#y}"
		b="${#z}"
		echo $((a+b))
	fi
done