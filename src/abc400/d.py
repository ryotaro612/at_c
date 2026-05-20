import os
import sys
import heapq

sys.setrecursionlimit(10**7)


def dbg(*args):
    if os.environ.get("ATCODER") == "1":
        print(*args)


h, w = map(int, input().split())


grid = [input() for _ in range(h)]
start_r, start_c, goal_r, goal_c = map(int, input().split())
start_r -= 1
start_c -= 1
goal_r -= 1
goal_c -= 1

costs = [[float("inf")] * w for _ in range(h)]
costs[start_r][start_c] = 0
heap = []
heapq.heappush(heap, (0, start_r, start_c))

while heap:
    cost, r, c = heapq.heappop(heap)
    if costs[r][c] < cost:
        continue
    for s_r, s_c, s_r2, s_c2 in [
        (r - 1, c, r - 2, c),
        (r, c + 1, r, c + 2),
        (r + 1, c, r + 2, c),
        (r, c - 1, r, c - 2),
    ]:
        if not (0 <= s_r < h and 0 <= s_c < w):
            continue
        if grid[s_r][s_c] == ".":
            if cost < costs[s_r][s_c]:
                costs[s_r][s_c] = cost
                heapq.heappush(heap, (cost, s_r, s_c))
            continue

        if cost + 1 < costs[s_r][s_c]:
            costs[s_r][s_c] = cost + 1
            heapq.heappush(heap, (cost + 1, s_r, s_c))

        if 0 <= s_r2 < h and 0 <= s_c2 < w:
            if cost + 1 < costs[s_r2][s_c2]:
                costs[s_r2][s_c2] = cost + 1
                heapq.heappush(heap, (cost + 1, s_r2, s_c2))

print(costs[goal_r][goal_c])
