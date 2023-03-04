#!/opt/homebrew/bin/python3

from sys import stderr
from random import randrange as rand

k = min(int(input()), 6)
n = 10**k
for _ in range(7 - k):
    lhs = sorted(rand(-(1 << 31), 1 << 31) for _ in range(n))
    rhs = sorted(rand(-(1 << 31), 1 << 31) for _ in range(n))
    print(n, n)
    print(' '.join(str(i) for i in lhs))
    print(' '.join(str(i) for i in rhs))
    print(' '.join(str(i) for i in sorted(lhs + rhs)), file=stderr)
