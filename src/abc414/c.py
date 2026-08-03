mport os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


a = int(input())
n = int(input())


cands = []
for i in range(1, 10):
    if i <= n:
        cands.append(i)
i = 1
while True:
    s = str(i)
    p = int(s + s[::-1])
    if p <= n:
        cands.append(p)
    else:
        break

    for j in range(10):
        p = int(s + str(j) + s[::-1])
        if p <= n:
            cands.append(p)
    i += 1
    dbg(i, len(str(i) + str(i)[::-1]))

res = 0
cands = sorted(cands)
# print(cands)
for cand in cands:
    i = 0

    while a**i <= cand:
        i += 1
    i -= 1
    temp = []
    c = cand
    for j in range(i, -1, -1):
        d = c // (a**j)
        temp.append(str(d))
        c -= d * (a**j)

    temp = "".join(temp)
    if temp == temp[::-1]:
        res += cand

print(res)
