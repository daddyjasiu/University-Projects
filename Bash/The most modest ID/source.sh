#Jan Skwarczek
#!/bin/bash
declare -a tab
end=0
Z=0
il=0
illow=10000
fin="a"

while (($end == 0))
do
        read idx
        if [[ "$idx" == "" ]]
        then
                end=1
        else
                tab[Z]="$idx"
                Z=$((Z + 1))
        fi
done

#echo "${tab[@]}"

for (( i=0; i<Z; i++ ))
do
        for (( k=0; k<Z; k++ ))
        do
            if [[ ${tab[i]} == ${tab[k]}  ]]
            then    
                    il=$((il + 1))  
            fi
        done
        if [[ $il -lt $illow ]]
        then
                illow=$il
                fin=${tab[i]}
        fi
        il=0 
done

echo $fin $illow 