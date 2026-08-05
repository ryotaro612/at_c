import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, h, m = map(int, input().split())


dp = [[-float("inf")] * (h + 1) for _ in range(n + 1)]

dp[0][h] = m

res = 0
for i in range(n):
    a, b = map(int, input().split())
    dbg(i)
    for j in range(h + 1):
        if j - a >= 0 and dp[i][j] >= 0:
            dp[i + 1][j - a] = max(dp[i][j], dp[i + 1][j - a])
            res = max(res, i + 1)
            # dbg("j-a", j, a)

        if dp[i][j] - b >= 0:
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - b)
            # dbg("after", dp[i][j], b)
            res = max(res, i + 1)

print(res)
