import os
import heapq
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())

xl = map(int, input().split())

order = sorted(list(set(xl)))
heap = []

for i in range(1, len(order)):
    heapq.heappush(heap, -(order[i] - order[i - 1]))

res = order[-1] - order[0]
cnt = 1
while cnt < m and heap:
    dist = -heapq.heappop(heap)
    res -= dist
    cnt += 1

print(res)
