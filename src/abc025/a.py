import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


s = input()
lst = []
for c in s:
    for d in s:
        lst.append(c + d)

n = int(input())

print(lst[n - 1])
