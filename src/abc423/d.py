import os
import sys
import heapq
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, k = map(int, input().split())

cur = 0
time = 0
heap = []
for _ in range(n):
    a, b, c = map(int, input().split())

    # heap -> (time, num)
    while heap and k < cur + c:
        t, num_cus = heapq.heappop(heap)
        time = t
        cur -= num_cus

    time = max(time, a)
    print(time)
    cur += c
    heapq.heappush(heap, (time + b, c))
