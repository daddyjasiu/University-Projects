#Jan Skwarczek
#!/bin/bash

read Z

num1=0
num2=1

for (( i=0; i<Z; i++))
do
	echo -e "$num1"
	temp=$((num1 + num2))
	num1=$num2
	num2=$temp
done