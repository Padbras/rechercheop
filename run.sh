#!/bin/bash

#file name of the knpsack instance
fileName=ks_1000.dat

#nombre d'exécutions
nbRun=100

#numbere of eval
nbEvalList=" 500 1000 2000 5000 10000 30000 50000 75000 100000"
#nbEvalList="50000"

#random search
#echo random search
#
#echo nbeval fitness > rs.csv
#for n in ${nbEvalList}
#do
#    echo nbEval ${n}
#   for((i=1;i<=${nbRun};i++))
#     do
#          echo -n $i' '
#          ./main ${fileName} ${n} ${i} >> rs.csv
#     done
#     echo
#done
#echo

#random march
#echo random march

#echo fitness > rs2.csv
#for n in ${nbEvalList}
#do
#    echo nbEval ${n}
#    for((i=1;i<=${nbRun};i++))
#     do
#          echo -n $i' '
#          ./main ${fileName} ${n} ${i} >> rs2.csv
#     done
#     echo
#done
#echo

echo hill climber best

echo nbeval fitness fitmax > fi.csv
for n in ${nbEvalList}
do
    echo nbEval ${n}
    for((i=1;i<=${nbRun};i++))
     do
          echo -n $i' '
          ./main ${fileName} ${n} ${i} >> fi.csv
     done
     echo
done
echo
