import os
import sys
from collections import defaultdict, deque
import heapq

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


h, w = map(int, input().split())

grid = []
letters = defaultdict(list)
for r in range(h):
    grid.append(input())
    for c in range(w):
        if grid[r][c].isalpha():
            letters[grid[r][c]].append((r, c))

dist = [[1e20] * w for _ in range(h)]

dist[0][0] = 0
que = deque([])
que.append((0, 0, 0))

while que:
    d, r, c = que.popleft()

    if dist[r][c] < d:
        continue

    for dr, dc in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        sr, sc = r + dr, c + dc
        if (
            0 <= sr < h
            and 0 <= sc < w
            and grid[sr][sc] != "#"
            and dist[r][c] + 1 < dist[sr][sc]
        ):
            dist[sr][sc] = dist[r][c] + 1
            que.append((dist[sr][sc], sr, sc))

    if grid[r][c].isalpha():
        for sr, sc in letters[grid[r][c]]:
            if dist[r][c] + 1 < dist[sr][sc]:
                dist[sr][sc] = dist[r][c] + 1
                que.append((dist[sr][sc], sr, sc))
        letters[grid[r][c]] = []

if dist[-1][-1] < 1e20:
    print(dist[-1][-1])
else:
    print(-1)
