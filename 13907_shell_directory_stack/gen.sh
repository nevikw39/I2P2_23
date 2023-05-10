#!/bin/zsh

for i in {1..9}; do
    echo $i | ./gen.py > testcases/in0$i.txt
    time ./solve < testcases/in0$i.txt > testcases/out0$i.txt
done
