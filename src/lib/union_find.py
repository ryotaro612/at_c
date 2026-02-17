class UnionFind:
    def __init__(self, n):
        self.par = [-1] * n

    def find_root(self, a):
        if self.par[a] < 0:
            return a

        self.par[a] = self.find_root(self.par[a])

        return self.par[a]

    def same(self, a, b):
        return self.find_root(a) == self.find_root(b)

    def unite(self, a: int, b: int):

        if self.same(a, b):
            return

        root_a = self.find_root(a)
        root_b = self.find_root(b)

        if self.par[root_a] < self.par[root_b]:
            self.par[root_a] += self.par[root_b]
            self.par[root_b] = root_a
        else:
            self.par[root_b] += self.par[root_a]
            self.par[root_a] = root_b
