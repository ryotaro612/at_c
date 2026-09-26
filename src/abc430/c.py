import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, a, b = map(int, input().split())

s = input()
c_a = 0
i_a = 0
c_b = 0
i_b = 0
res = 0
for l, c in enumerate(s):
    dbg("l", l, "c_a", c_a)
    while c_a < a and i_a < n:
        if s[i_a] == "a":
            c_a += 1
        i_a += 1

    while c_b < b and i_b < n:
        if s[i_b] == "b":
            c_b += 1
        i_b += 1

    if i_b == n:
        temp = n
    else:
        temp = i_b - 1

    if c_b < b:
        temp = n
    else:
        temp = i_b - 1

    if c_a == a and (i_a - 1) < (i_b - 1):
        res += (i_b - 1) - (i_a - 1)

    dbg(l, res, "c_a", c_a, "i_a", i_a, "c_b", c_b, "i_b", i_b)

    if s[l] == "a":
        c_a -= 1
    else:
        c_b -= 1


print(res)
