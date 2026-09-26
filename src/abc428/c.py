import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


q = int(input())


cnt = [0]
neg = 0
for _ in range(q):
    line = input()
    if line[0] == "1":
        a = 1 if line[2] == "(" else -1
        cnt.append(cnt[-1] + a)
        if cnt[-1] < 0:
            neg += 1
    else:
        if cnt.pop() < 0:
            neg -= 1

    if cnt[-1] == 0 and neg == 0:
        print("Yes")
    else:
        print("No")
