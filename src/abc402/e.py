import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, x = map(int, input().split())
# sl scores
# cl costs
# pl success probabilities
sl, cl, pl = [], [], []

for _ in range(n):
    s, c, p = map(int, input().split())
    sl.append(s)
    cl.append(c)
    pl.append(p)

dp = [[-float("inf")] * (x + 1) for _ in range(1 << n)]


def rec(mask: int, rem: int, dp: list[list[float]]):
    if dp[mask][rem] >= 0:
        return dp[mask][rem]
    best = 0
    for i in range(n):
        if (mask & (1 << i)) == 0 and rem >= cl[i]:
            succ = (sl[i] + rec(mask | (1 << i), rem - cl[i], dp)) * pl[i] / 100
            fail = rec(mask, rem - cl[i], dp) * (100 - pl[i]) / 100
            best = max(best, succ + fail)
    dp[mask][rem] = best
    return best


print(rec(0, x, dp))
