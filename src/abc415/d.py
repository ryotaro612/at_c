import os
import sys
import heapq
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())
heap = []

for _ in range(m):
    a, b = map(int, input().split())
    heapq.heappush(heap, (a - b, a, b))

res = 0
while heap:
    diff, a, b = heapq.heappop(heap)
    # n >= a
    dbg("entry", diff, a, b)
    dbg("n", n)
    while a <= n:
        dbg("a <= n")
        dec = (n - a) // diff
        dbg(dec)
        res += dec

        n -= dec * diff

        if a <= n:
            res += 1
            n -= diff


print(res)
