import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


class Rmq:
    def __init__(self, n, init, key=lambda x: x):
        self._key = key
        self._init = init
        exp = 0
        while (1 << exp) < n:
            exp += 1

        self._n_leaves = 1 << exp
        n_node = 1 << (exp + 1)
        self._items = [self._init] * n_node
        # _lazy の初期値は _init ではなく None にして区別する
        self._lazy = [None] * n_node

    def query(self, left, right):
        return self._query(left, right, 0, 0, self._n_leaves)

    def get(self, i):
        return self.query(i, i + 1)

    def set(self, i, x):
        self.update(i, i + 1, x)

    def update(self, left, right, x):
        self._update(left, right, x, 0, 0, self._n_leaves)

    def _query(self, a, b, k, l, r):
        self._eval(k)

        if b <= l or r <= a:
            return self._init
        if a <= l and r <= b:
            return self._items[k]

        vl = self._query(a, b, 2 * k + 1, l, (l + r) // 2)
        vr = self._query(a, b, 2 * k + 2, (l + r) // 2, r)

        if self._key(vl) <= self._key(vr):
            return vl
        else:
            return vr

    def _update(self, a, b, x, k, l, r):
        self._eval(k)

        if b <= l or r <= a:
            return

        if a <= l and r <= b:
            self._lazy[k] = x
            self._eval(k)
            return

        self._update(a, b, x, k * 2 + 1, l, (l + r) // 2)
        self._update(a, b, x, k * 2 + 2, (l + r) // 2, r)

        if self._key(self._items[2 * k + 1]) <= self._key(self._items[2 * k + 2]):
            self._items[k] = self._items[2 * k + 1]
        else:
            self._items[k] = self._items[2 * k + 2]

    def _eval(self, k):
        if self._lazy[k] is None:
            return

        if k < self._n_leaves - 1:
            self._lazy[2 * k + 1] = self._lazy[k]
            self._lazy[2 * k + 2] = self._lazy[k]

        self._items[k] = self._lazy[k]
        self._lazy[k] = None


n, d, r = map(int, input().split())
hl = [int(h) - 1 for h in input().split()]

ord_pos = [-1] * n
for i in range(n):
    ord_pos[hl[i]] = i

res = [-1] * n

rmq = Rmq(n, -float("inf"), lambda x: -x)
for i in range(n):
    rmq.set(i, -1)


res[0] = 0

for i in range(1, n):
    if i - d >= 0:
        dbg("->", ord_pos[i - d], res[i - d])
        rmq.set(ord_pos[i - d], res[i - d])

    pos = ord_pos[i]
    n_step = rmq.query(pos + 1, min(n, pos + r + 1))
    m_step = rmq.query(max(0, pos - r), pos)

    step = max(n_step, m_step)
    if step >= 0:
        res[i] = step + 1
    else:
        res[i] = 0
    dbg("i", i, "res[i]", res[i], "pos", pos, "n_step", n_step, "m_step", m_step)


print(max(res))
