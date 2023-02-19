#!/opt/homebrew/bin/python3

from sys import stderr
from random import randrange as rand
from statistics import median as me

k = int(input())
n = 10**k
for _ in range(6 - k):
    lst = [rand(-(1 << 31), 1 << 31) for _ in range(n)]
    m = int(me(lst))
    print(n, m)
    print(' '.join(str(i) for i in lst))
    print(' '.join(str(i) for i in ([i for i in lst if i < m] + [i for i in lst if i >= m])), file=stderr)
