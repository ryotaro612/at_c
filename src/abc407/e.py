import os
import sys
from collections import defaultdict, deque
import heapq

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))

t = int(input())

for _ in range(t):
    n = int(input())

    heap = []

    a = int(input())
    res = a

    for i in range(n-1):
        a1 = int(input())
        a2 = int(input())
        heapq.heappush(heap, -a1)
        heapq.heappush(heap, -a2)
        res -= heapq.heappop(heap)

    print(res)
    input()

        




    
