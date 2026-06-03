import os
import sys
from collections import defaultdict


sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())


kl = []
for _ in range(n):
    k, *l = map(int, input().split())

    dbg(l)
    probs = defaultdict(lambda: 0.0)
    for e in l:
        probs[e] += 1 / k

    kl.append(probs)

dbg(kl)

res = 0
for i in range(n):
    for j in range(i + 1, n):
        temp = 0.0
        for e in kl[i].keys():
            dbg(i, j, e, kl[i][e], kl[j][e])
            temp += kl[i][e] * kl[j][e]

        res = max(res, temp)

print(res)
