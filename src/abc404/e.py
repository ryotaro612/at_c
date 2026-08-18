import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())

cl = list(map(int, input().split()))
cl = [0] + cl
al = list(map(int, input().split()))
al = [0] + al
dist = [1e20] * n

dist[0] = 0

res = 0

for i in range(1, n):
    for j in range(1, cl[i] + 1):
        if i - j >= 0:
            if al[i - j]:
                dist[i] = min(dist[i], 1)
            else:
                dist[i] = min(dist[i], dist[i - j] + 1)

dbg(dist)
for i in range(n - 1, 0, -1):
    if al[i]:
        dbg(al[i], i)
        res += dist[i]
print(res)
