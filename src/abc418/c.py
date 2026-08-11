import os
import sys
from collections import defaultdict
import bisect


sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, q = map(int, input().split())

al = sorted(list(map(int, input().split())))

prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + al[i]


for _ in range(q):
    b = int(input())
    lb = -1
    ub = n
    while ub - lb > 1:
        mid = (ub + lb) // 2
        if al[mid] < b:
            lb = mid
            continue
        ub = mid
    if ub == n:
        print(-1)
    else:
        print(1 + prefix[ub] + (b - 1) * (n - ub))
