import os
import sys

# 高速化のための Fast I/O
input = sys.stdin.read


class UnionFind:
    def __init__(self, n):
        self.n = n
        self.par = [-1] * n
        self.black = [0] * n  # 各グループ（根）に属する黒頂点の個数

    def find_root(self, a):
        if self.par[a] < 0:
            return a
        self.par[a] = self.find_root(self.par[a])
        return self.par[a]

    def is_same_group(self, a, b):
        return self.find_root(a) == self.find_root(b)

    def unite(self, a, b):
        root_a = self.find_root(a)
        root_b = self.find_root(b)
        if root_a == root_b:
            return

        # サイズによる統合（Rank/Size-based Union）
        if self.par[root_a] < self.par[root_b]:
            self.par[root_a] += self.par[root_b]
            self.par[root_b] = root_a
            self.black[root_a] += self.black[root_b]  # 黒の個数を合算
        else:
            self.par[root_b] += self.par[root_a]
            self.par[root_a] = root_b
            self.black[root_b] += self.black[root_a]  # 黒の個数を合算


def solve():
    data = input().split()
    if not data:
        return

    n = int(data[0])
    q = int(data[1])

    uf = UnionFind(n)
    color = [False] * n

    idx = 2
    out = []

    for _ in range(q):
        t = data[idx]
        if t == "1":
            u = int(data[idx + 1]) - 1
            v = int(data[idx + 2]) - 1
            uf.unite(u, v)
            idx += 3

        elif t == "2":
            v = int(data[idx + 1]) - 1
            root = uf.find_root(v)
            if color[v]:
                color[v] = False
                uf.black[root] -= 1
            else:
                color[v] = True
                uf.black[root] += 1
            idx += 2

        else:
            v = int(data[idx + 1]) - 1
            root = uf.find_root(v)
            if uf.black[root] > 0:
                out.append("Yes")
            else:
                out.append("No")
            idx += 2

    print("\n".join(out))


if __name__ == "__main__":
    solve()
