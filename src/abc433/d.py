import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())

al = list(map(int, input().split()))

am = [defaultdict(int) for _ in range(12)]

for i, a in enumerate(al):
    for j in range(12):
        am[j][a * (10**j) % m] += 1

res = 0

for i in range(12):
    dbg(i, am[i])
for a in al:
    c = a % m
    dbg(c, m - c)
    if c:
        res += am[len(str(a))][m - c]
    else:
        res += am[len(str(a))][0]


print(res)
