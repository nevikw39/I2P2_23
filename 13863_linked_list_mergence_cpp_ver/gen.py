#!/usr/bin/python3

from string import ascii_letters
from sys import stderr
import random

k = min(int(input()), 5)
n = 10**k
for _ in range(6 - k):
    li = [random.randrange(-(1 << 31), 1 << 31) for _ in range(n)]
    ls = [''.join(random.choices(ascii_letters, k=1+random.randrange(10))) for _ in range(n)]
    print(n, n)
    print(' '.join(str(i) for i in li))
    print(' '.join(i for i in ls))
    for i in sorted(li):
        print(i, file=stderr)
    for i in sorted(ls):
        print(i, file=stderr)
