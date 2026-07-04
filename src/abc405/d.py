import os
import sys
from collections import deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


h, w = map(int, input().split())

grid = []


for r in range(h):
    grid.append(list(input()))

que = deque()

for r in range(h):
    for c in range(w):
        if grid[r][c] == "E":
            for sr, sc, f in [
                (r - 1, c, "v"),
                (r, c + 1, "<"),
                (r + 1, c, "^"),
                (r, c - 1, ">"),
            ]:
                if 0 <= sr < h and 0 <= sc < w and grid[sr][sc] == ".":
                    grid[sr][sc] = f
                    que.append((sr, sc))


cand = {"^", "v", "<", ">", "E"}
while que:
    r, c = que.popleft()

    for sr, sc, f in [
        (r - 1, c, "v"),
        (r, c + 1, "<"),
        (r + 1, c, "^"),
        (r, c - 1, ">"),
    ]:
        if 0 <= sr < h and 0 <= sc < w and grid[sr][sc] == ".":
            grid[sr][sc] = f
            que.append((sr, sc))


for r in range(h):
    print("".join(grid[r]))
