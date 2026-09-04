import os
import sys
from collections import defaultdict, deque
import bisect

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


class Bit:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, x):
        i += 1
        while i <= self.n:
            self.bit[i] += x
            i += i & -i

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l)


n, m = map(int, input().split())
bit = Bit(n * 2)

bal = []

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    bit.add(a, 1)
    bal.append((b, a))

bal.sort(reverse=True)


q = int(input())

cdl = []

for i in range(q):
    c, d = map(int, input().split())
    c -= 1
    d -= 1
    cdl.append((d, c, i))

cdl.sort()

res = [0] * q

for d, c, i in cdl:
    while bal and bal[-1][0] <= d:
        b, a = bal.pop()
        bit.add(a, -2)
        bit.add(b, 1)

    res[i] = bit.range_sum(c, d + 1)

for e in res:
    print(e)
