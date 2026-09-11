import os
import sys
import heapq
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


heap = []


n, q = map(int, input().split())

for i in range(1, n + 1):
    heapq.heappush(heap, (i, 1))

for _ in range(q):
    x, y = map(int, input().split())
    res = 0
    while heap and heap[0][0] <= x:
        v, c = heapq.heappop(heap)
        res += c

    heapq.heappush(heap, (y, res))
    print(res)
