import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())

g = [[] for _ in range(n)]

edges = []
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges.append([a, b])

res = 1e20

for mask in range(1 << n):
    cur = 0
    for a, b in edges:
        a_b = mask & (1 << a)
        b_b = mask & (1 << b)
        if a_b and b_b:
            cur += 1
        elif not a_b and not b_b:
            cur += 1
    res = min(res, cur)
print(res)
