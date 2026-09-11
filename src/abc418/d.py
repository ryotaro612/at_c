import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())

t = [int(a) for a in input()]

dp = [0 for _ in range(n)]

res = 0

if t[0]:
    dp[0] = 1
    res = 1

for i in range(1, n):
    cnt = i + 1

    if cnt % 2:
        if t[i]:
            res += dp[i - 1] + 1
            dp[i] = dp[i - 1] + 1
        else:
            res += i - dp[i - 1]
            dp[i] = i - dp[i - 1]
    else:
        if t[i]:
            res += dp[i - 1] + 1
            dp[i] = dp[i - 1] + 1
        else:
            dp[i] = i - dp[i - 1]
            res += i - dp[i - 1]


print(res)
