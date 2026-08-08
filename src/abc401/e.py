import os
import sys
import heapq
from collections import defaultdict
from typing import Union

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


class UnionFind:
    def __init__(self, n):
        self.n = n
        self.par = [-1] * n

    def find_root(self, a):
        if self.par[a] < 0:
            return a
        self.par[a] = self.find_root(self.par[a])
        return self.par[a]

    def is_same_group(self, a, b):
        return self.find_root(a) == self.find_root(b)

    def unite(self, a, b):
        if self.is_same_group(a, b):
            return
        root_a = self.find_root(a)
        root_b = self.find_root(b)
        if self.par[root_a] < self.par[root_b]:
            self.par[root_a] += self.par[root_b]
            self.par[root_b] = root_a
        else:
            self.par[root_b] += self.par[root_a]
            self.par[root_a] = root_b

    def group_size(self, a):
        return -self.par[self.find_root(a)]


n, m = map(int, input().split())
g = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)


uf = UnionFind(n)

heap = []
counter = defaultdict(int)


for node in range(n):
    for succ in g[node]:
        if succ < node:
            uf.unite(node, succ)
        else:
            if counter[succ] == 0:
                counter[succ] += 1
                heapq.heappush(heap, succ)

    if uf.group_size(node) == node + 1:
        while heap and heap[0] <= node:
            counter[heapq.heappop(heap)] -= 1

        dbg(node, heap)
        print(len(heap))
    else:
        print(-1)
