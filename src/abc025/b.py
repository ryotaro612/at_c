import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, a, b = map(int, input().split())

res = 0

for _ in range(n):
    s, d = input().split()
    d = int(d)
    d = max(a, d)
    d = min(b, d)
    if s == "East":
        res += d
    else:
        res -= d

if res > 0:
    print("East", abs(res))
elif res == 0:
    print(0)
else:
    print("West", abs(res))
