import os
from typing import Any
import sys
from collections import defaultdict
from sortedcontainers import SortedList

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    al = list(map(int, input().split()))
    bl: list[int] = list(map(int, input().split()))
    bsl: Any = SortedList(bl)

    res = 0
    for a in sorted(al):
        i = bsl.bisect_left(m - a)
        if i < len(bsl):
            res += (a + bsl[i]) % m
            del bsl[i]
        else:
            res += (a + bsl[0]) % m
            del bsl[0]

    print(res)
