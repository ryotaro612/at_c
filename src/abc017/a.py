import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


res = 0
for _ in range(3):
    s, e = map(int, input().split())
    res += s // 10 * e

print(res)
