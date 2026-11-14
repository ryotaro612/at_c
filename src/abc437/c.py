import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))

t = int(input())

for _ in range(t):
    n = int(input())
    wp = []
    for _ in range(n):
        w, p = map(int, input().split())
        wp.append((w, p))

    wp.sort(key=lambda x: x[0] + x[1])

    total = sum([e[1] for e in wp])
    res = 0
    acc = 0
    for i in range(n):
        dbg(i)
        acc += wp[i][0] + wp[i][1]
        if acc > total:
            print(i)
            break


    
