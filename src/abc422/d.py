import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**8)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, k = map(int, input().split())


def solve(n: int, k: int):
    if n == 1:
        a = k // 2
        c, d = max(a, k - a), min(a, k - a)
        return [c, d]

    a = solve(n - 1, k // 2)
    b = solve(n - 1, k - k // 2)

    return a + b


al = solve(n, k)

res = 0
bl = list(al)

while bl:
    res = max(res, max(bl) - min(bl))
    nxt = []
    while 2 < len(bl):
        nxt.append(bl.pop() + bl.pop())
    nxt = nxt[::-1]
    bl = nxt
print(res)
print(" ".join(map(str, al)))
