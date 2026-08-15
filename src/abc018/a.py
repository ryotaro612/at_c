import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


al = []
for i in range(3):
    al.append((int(input()), i))

al.sort(reverse=True)

res = [0] * 3
for i in range(3):
    res[al[i][1]] = i + 1

for r in res:
    print(r)
