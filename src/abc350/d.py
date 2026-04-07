import os
import sys
sys.setrecursionlimit(10**7)

def dbg(*args):
    if os.environ.get("ATCODER") == "1":
        print(*args)


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

uf = UnionFind(n)

for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    uf.unite(a, b)

mp = dict()

for i in range(n):
    mp[uf.find_root(i)] = uf.group_size(i)

total = 0
for siz in mp.values():
    total += siz * (siz - 1) // 2

print(total - m)
