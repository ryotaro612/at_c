import os
import sys
from collections import defaultdict, deque
import bisect

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


class Bit:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, x):
        i += 1
        while i <= self.n:
            self.bit[i] += x
            i += i & -i

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l)


def calc_dist(a: int, b: int, n: int):
    counter = b - a
    clockwise = 2 * n + a - b
    if counter < clockwise:
        dbg("a", a, "b", b, counter, -a)
        return counter, -a

    dbg("a", a, "b", b, counter, 2 * n - b)
    return clockwise, 2 * n - b


n, m = map(int, input().split())
abl = []

for _ in range(m):
    a, b = map(int, input().split())
    abl.append((a - 1, b - 1))
q = int(input())


pivot_dist, move = calc_dist(abl[0][0], abl[0][1], n)
pivot_i = 0

for i in range(1, m):
    current_dist, currrent_move = calc_dist(abl[i][0], abl[i][1], n)
    if current_dist < pivot_dist:
        pivot_i = i
        pivot_dist = current_dist
        move = currrent_move

dbg("move", move)

for i in range(m):
    a, b = abl[i]
    a = (a + move) % (2 * n)
    b = (b + move) % (2 * n)
    abl[i] = (min(a, b), max(a, b))

abl.sort()

dbg("abl", abl)

order = []
for i in range(m):
    if i == 0:
        order.append((abl[i][0], 0))
        order.append((abl[i][1], 1))
    else:
        order.append((abl[i][0], i + 1))
        order.append((abl[i][1], i))

order.sort()
dbg("order", order)

for _ in range(q):
    c, d = [int(x) - 1 for x in input().split()]

    c = (c + move + 2 * n) % (2 * n)
    dbg("c", c)
    d = (d + move + 2 * n) % (2 * n)
    c, d = min(c, d), max(c, d)

    dbg("c", c, "d", d)

    c_i = bisect.bisect_left(order, (c, 0))
    d_i = bisect.bisect_left(order, (d, 0))

    print(abs(order[c_i - 1][1] - order[d_i - 1][1]))
