import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


m, d = map(int, input().split())

if m % d == 0:
    print("YES")
else:
    print("NO")
