import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


h, w = map(int, input().split())
grid = []

que = deque()
for r in range(h):
    grid.append(list(input()))

    for c, v in enumerate(grid[-1]):
        que.append([r, c])


while que:
    next_que = deque()

    while que:
        r, c = que.popleft()
        if grid[r][c] == "#":
            continue

        cnt = 0
        succ = []
        for dr, dc in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
            s_r, s_c = r + dr, c + dc
            if 0 <= s_r < h and 0 <= s_c < w:
                succ.append([s_r, s_c])

        for s_r, s_c in succ:
            if grid[s_r][s_c] == "#":
                cnt += 1

        if cnt == 1:
            next_que.append([r, c])

    while next_que:
        r, c = next_que.popleft()
        grid[r][c] = "#"

        for dr, dc in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
            s_r, s_c = r + dr, c + dc
            if 0 <= s_r < h and 0 <= s_c < w:
                que.append([s_r, s_c])


cnt = 0
for r in range(h):
    for c in range(w):
        if grid[r][c] == "#":
            cnt += 1

# for r in range(h):
#     print("".join(grid[r]))
print(cnt)
