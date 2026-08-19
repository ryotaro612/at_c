import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())
    dbg(a, b, c)
    ub = min(a, c) + 1
    lb = -1

    while ub - lb > 1:
        mid = (ub + lb) // 2
        dbg(mid)
        if a - mid + b + c - mid < mid:
            ub = mid
            # dbg("lb")
        else:
            lb = mid
            # dbg("ub")

    print(lb)
