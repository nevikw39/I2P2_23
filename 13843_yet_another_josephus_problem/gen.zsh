arr=("13 843" "78 89" "87 69" "174 89" "426 92" "689 733" "817 64" "1989 64" "100000 10000" "100000 1000000000")
mkdir -p testcases
for i in {0..9}; do
    echo ${arr[$((i+1))]} | tee testcases/in0$i.txt | time ./solve_treap > testcases/out0$i.txt
    diff <(cat testcases/in0$i.txt | ./solve_bit) testcases/out0$i.txt
done
