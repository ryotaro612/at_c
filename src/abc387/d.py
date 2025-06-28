from collections import deque


h, w = map(int, input().split())
grid = [input() for _ in range(h)]

inf = 10**9
d = [[None] * w for _ in range(h)]
for r in range(h):
    for c in range(w):
        d[r][c] = [inf, inf]

que = deque([])

for r in range(h):
    for c in range(w):
        if grid[r][c] == "S":
            d[r][c][0] = 0
            d[r][c][1] = 0
            que.append((r, c, 0))
            que.append((r, c, 1))
        if grid[r][c] == "G":
            g_r, g_c = r, c

while que:
    r, c, move = que.popleft()
    succs = []
    if move == 0:
        for s_r in [r - 1, r + 1]:
            if 0 <= s_r < h and grid[s_r][c] != "#":
                succs.append((s_r, c, 1))
    else:
        for s_c in [c - 1, c + 1]:
            if 0 <= s_c < w and grid[r][s_c] != "#":
                succs.append((r, s_c, 0))

    for s_r, s_c, s_move in succs:
        cost = d[r][c][move] + 1
        if cost < d[s_r][s_c][s_move]:
            d[s_r][s_c][s_move] = cost
            que.append((s_r, s_c, s_move))

res = min(d[g_r][g_c])
print(res if res < inf else -1)
