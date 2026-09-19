import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, q = map(int, input().split())

al = [int(a) for a in input().split()]


prefix = [0] * (n + 1)
prefix2 = [0] * (n + 1)
prefix3 = [0] * (n + 1)

for i in range(n):
    prefix[i + 1] = prefix[i] + (i + 1) ** 2 * al[i]
    prefix2[i + 1] = prefix2[i] + (i + 1) * al[i]
    prefix3[i + 1] = prefix3[i] + al[i]

for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    res = (
        -(prefix[r + 1] - prefix[l])
        + (l + r + 2) * (prefix2[r + 1] - prefix2[l])
        + (-(l + 1) + 1) * (r + 2) * (prefix3[r + 1] - prefix3[l])
    )
    print(res)
