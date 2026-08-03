import os
import math
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())

al = list(map(int, input().split()))

res = 0
for a in al:
    res += a

print(math.ceil(res / len([a for a in al if a])))
