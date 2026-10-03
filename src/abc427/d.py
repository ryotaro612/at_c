import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())


def traverse(k, ab, node, dp, g, s):
    if dp[node][ab][k] != -1:
        return dp[node][ab][k]

    if k == 0:
        dp[node][ab][k] = 1 if s[node] == "A" else 0
        return dp[node][ab][k]

    for succ in g[node]:
        if not traverse(k - 1, 1 - ab, succ, dp, g, s):
            dp[node][ab][k] = 1
            return 1
    dp[node][ab][k] = 0
    return 0


for _ in range(t):
    n, m, k = map(int, input().split())
    s = input()
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append(v)

    dp = [[[-1] * (k * 2 + 1) for _ in range(2)] for _ in range(n)]

    if traverse(k * 2, 0, 0, dp, g, s):
        print("Alice")
    else:
        print("Bob")
