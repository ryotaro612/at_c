import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())


g = [[] for _ in range(n)]


def traverse(g, mask):
    n = len(g)
    d = [1e30] * n
    que = deque()
    d[0] = 0
    que.append(0)

    while que:
        node = que.popleft()
        for succ, w in g[node]:
            if (w & mask) or (d[succ] <= (d[node] + 1)):
                continue

            if succ == n - 1:
                return True
            d[succ] = d[node] + 1
            que.append(succ)

    return d[n - 1] < 1e30


for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append([v, w])
    g[v].append([u, w])

mask = 0
for i in range(29, -1, -1):
    if traverse(g, mask | (1 << i)):
        mask |= 1 << i


def dfs(g, node, visited):
    n = len(g)
    if node == n - 1:
        return 0

    res = int(1e30)
    for succ, w in g[node]:
        if (w & mask) or visited[succ]:
            continue

        visited[succ] = True
        res = min(res, w | dfs(g, succ, visited))

    return res


visited = [False] * n

print(dfs(g, 0, visited))
