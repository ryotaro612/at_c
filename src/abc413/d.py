import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


def sub(al: list[int]) -> bool:
    dbg(al)
    n = len(al)
    if n == 1:
        return True

    for i in range(2, n):
        if al[i - 1] * al[i - 1] != al[i] * al[i - 2]:
            return False
    return True


def add(al, bl):
    res = []
    al = list(al)
    bl = list(bl)
    while al or bl:
        if al:
            res.append(al.pop())
        if bl:
            res.append(bl.pop())

    return res


def solve(al: list[int]) -> bool:
    al.sort(key=lambda x: abs(x))

    cand = sorted([a for a in al if a > 0], reverse=True)
    cand_neg = sorted([a for a in al if a < 0])

    if len(cand) == 0 or len(cand_neg) == 0:
        return sub([abs(a) for a in al])
    if abs(len(cand) - len(cand_neg)) > 1:
        return False

    return sub(add(cand, cand_neg)) or sub(add(cand_neg, cand))


t = int(input())

for _ in range(t):
    input()
    al = list(map(int, input().split()))
    if solve(al):
        print("Yes")
    else:
        print("No")
