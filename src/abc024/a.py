import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))



a, b, c, k = map(int, input().split())
s, t = map(int, input().split())

res = a * s + b * t
if s + t >= k:
    res -= (s + t) * c

print(res)
