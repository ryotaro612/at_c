import sys

input = sys.stdin.readline


class BIT:
    def __init__(self, n: int):
        self.a = [0] * (n + 1)

    def add(self, i: int, x: int) -> None:
        i += 1
        while i < len(self.a):
            self.a[i] += x
            i += i & -i

    def sum(self, *args) -> int:
        if len(args) == 1:
            r = args[0]
            s = 0
            while r:
                s += self.a[r]
                r -= r & -r
            return s
        else:
            l, r = args
            return self.sum(r) - self.sum(l)

    # minimize i s.t. sum(i) >= w
    def lower_bound(self, w: int) -> int:
        x = 0
        n = len(self.a) - 1
        k = 1 << (n.bit_length() - 1)
        while k:
            if x + k <= n and self.a[x + k] < w:
                w -= self.a[x + k]
                x += k
            k >>= 1
        return x + 1


n, m = map(int, input().split())
a = [int(x) - 1 for x in input().split()]
c = [0] * m
for v in a:
    c[v] += 1
s = [(c[i], i) for i in range(m)]
s.sort()
r = [0] * (m + 1)
r[0] = n
for i in range(m - 1):
    r[i + 1] = (i + 1) * (s[i + 1][0] - s[i][0]) + r[i]
r[m] = 10**18 + 2026
q = int(input())
ans = [-1] * q
que = []
for i in range(q):
    x = int(input())
    if x <= n:
        ans[i] = a[x - 1]
        continue
    ng, ok = 0, m
    while ok - ng != 1:
        vs = (ok + ng) >> 1
        if r[vs] >= x:
            ok = vs
        else:
            ng = vs
    x -= r[ng] + 1
    x %= ok
    que.append((ok, x, i))
que.sort()
fw = BIT(m)
idx = 0
for ok, x, i in que:
    while idx < ok:
        fw.add(s[idx][1], 1)
        idx += 1
    ans[i] = fw.lower_bound(x + 1) - 1
for v in ans:
    print(v + 1)
