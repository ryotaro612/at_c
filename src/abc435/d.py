import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())


g = [[] for _ in range(n)]

for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    g[y].append(x)

blacks = [0] * n

q = int(input())


def mark(g, node, blacks):
    if blacks[node]:
        return
    blacks[node] = 1
    for child in g[node]:
        if blacks[child]:
            continue
        mark(g, child, blacks)


for _ in range(q):
    t, v = map(int, input().split())
    v -= 1
    if t == 1:
        mark(g, v, blacks)

    else:
        if blacks[v]:
            print("Yes")
        else:
            print("No")
