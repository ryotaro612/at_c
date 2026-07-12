import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


h, w, n = map(int, input().split())
row_map = defaultdict(set)
col_map = defaultdict(set)
for _ in range(n):
    x, y = map(int, input().split())
    row_map[x].add(y)
    col_map[y].add(x)

q = int(input())

for i in range(q):
    t, a = map(int, input().split())
    if t == 1:
        x = a
        print(len(row_map[x]))
        for y in row_map[x]:
            col_map[y].remove(x)
        row_map[x].clear()
    else:
        y = a
        print(len(col_map[y]))
        for x in col_map[y]:
            row_map[x].remove(y)
        col_map[y].clear()
