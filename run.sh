#!/bin/bash

#file name of the knpsack instance
fileName=ks_1000.dat

#nombre d'exécutions
nbRun=100

#numbere of eval
nbEvalList="10 50 100 500 1000 2000 5000 10000"
#nbEvalList="50000"

#random search
echo random search

echo nbeval fitness > rs.csv
for n in ${nbEvalList}
do
    echo nbEval ${n}
    for((i=0;i<${nbRun};i++))
     do
          echo -n $i' '
          ./main ${fileName} ${n} ${i} >> rs.csv
     done
     echo
done
echo
