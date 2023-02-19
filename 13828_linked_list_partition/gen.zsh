#!/bin/zsh

for i in $(seq 1 4); do
    echo $((i + 1)) | ./gen.py > testcases/in0$i.txt 2> testcases/out0$i.txt;
    diff <(./a.out < testcases/in0$i.txt) testcases/out0$i.txt;
done;