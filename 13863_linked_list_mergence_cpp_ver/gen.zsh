#!/bin/zsh

for i in $(seq 1 9); do
    echo $i | ./gen.py > testcases/in0$i.txt 2> testcases/out0$i.txt;
    diff <(time ./a.out < testcases/in0$i.txt) testcases/out0$i.txt;
done;