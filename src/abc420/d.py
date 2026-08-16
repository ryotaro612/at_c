import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


h, w = map(int, input().split())


grid = []

dist = [[[1e20] * 2 for _ in range(w)] for _ in range(h)]

que = deque()

res = 1e20

for r in range(h):
    grid.append(input())
    for c in range(w):
        if grid[r][c] == "S":
            que.append([0, r, c])
            dist[r][c][0] = 0


while que:
    flip, r, c = que.popleft()

    if grid[r][c] == "G":
        print(dist[r][c][flip])
        exit()

    symbols = {".", "S", "G"}
    if flip == 0:
        symbols.add("o")
    else:
        symbols.add("x")

    for dr, dc in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
        nr = r + dr
        nc = c + dc
        cost = dist[r][c][flip] + 1
        if not (0 <= nr < h and 0 <= nc < w):
            continue
        if grid[nr][nc] in symbols:
            if cost < dist[nr][nc][flip]:
                dist[nr][nc][flip] = cost
                que.append([flip, nr, nc])

        elif grid[nr][nc] == "?":
            if cost < dist[nr][nc][1 ^ flip]:
                dist[nr][nc][1 ^ flip] = cost
                que.append([1 ^ flip, nr, nc])
print(-1)
