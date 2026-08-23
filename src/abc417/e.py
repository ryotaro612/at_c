import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())


def solve(goal, g, visit, path):
    node = path[-1]
    if node == goal:
        return True

    while g[node]:
        if visit[g[node][-1]]:
            g[node].pop()
            continue
        succ = g[node].pop()
        visit[succ] = True
        path.append(succ)
        if solve(goal, g, visit, path):
            return True
        path.pop()
    return False


for _ in range(t):
    n, m, x, y = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = [int(x) - 1 for x in input().split()]
        g[u].append(v)
        g[v].append(u)

    for i in range(n):
        g[i].sort(reverse=True)

    visit = [False] * n
    x -= 1
    y -= 1
    res = [x]
    visit[x] = True
    assert solve(y, g, visit, res)
    print(" ".join([str(node + 1) for node in res]))
