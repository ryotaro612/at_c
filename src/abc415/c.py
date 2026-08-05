import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())
cache = dict()


def rec(s: str, cur: int, n: int) -> bool:
    if cur in cache:
        return cache[cur]

    if s[2**n - 2] == "1":
        cache[cur] = False
        return False
    if cur == 2**n - 1:
        cache[cur] = True
        return True

    for i in range(n):
        if cur & (1 << i):
            continue

        nxt = cur | (1 << i)
        if s[nxt - 1] == "1":
            continue

        if rec(s, nxt, n):
            cache[cur] = True
            return True
    cache[cur] = False
    return False


for i in range(t):
    # dbg(i)
    n = int(input())
    s = input()
    cache = dict()
    if rec(s, 0, n):
        print("Yes")
    else:
        print("No")
