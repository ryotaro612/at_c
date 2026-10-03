import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())


wl, hl, bl = [], [], []

for _ in range(n):
    w, h, b = map(int, input().split())
    wl.append(w)
    hl.append(h)
    bl.append(b)

remain = sum(wl)
dp = [[0, 0, 0]]
for i in range(n):
    w, h, b = wl[i], hl[i], bl[i]
    remain -= w
    nxt = []
    for head, body, value in dp:
        new_head = head + w

        if new_head <= body + remain:
            nxt.append([new_head, body, value + h])

        nxt.append([head, body + w, value + b])

    dp = nxt

print(max(value for _, _, value in dp))
