import os
import sys
from collections import defaultdict, deque

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


def create_order(node, parent, g, order, right_most):
    order.append(node)

    right_most[node] = node
    for child in g[node]:
        if child == parent:
            continue

        right_most[node] = create_order(child, node, g, order, right_most)
    return right_most[node]


n = int(input())

g = [[] for _ in range(n)]

yl = []
for _ in range(n - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    yl.append([u, v])
    g[u].append(v)
    g[v].append(u)

order = []
right_most = [-1] * n
create_order(0, -1, g, order, right_most)


node_order = [-1] * n
for i, o in enumerate(order):
    node_order[o] = i


# print("node-order", node_order)
# print("order", order)
q = int(input())
bit = Bit(n)
for i in range(n):
    bit.add(i, 1)

total = n
for i in range(q):
    line = input().split()
    if line[0] == "1":
        x, w = map(int, line[1:])
        x -= 1
        bit.add(node_order[x], w)
        total += w
    else:
        y = int(line[1]) - 1
        node = max(yl[y])
        a = bit.range_sum(node_order[node], node_order[right_most[node]] + 1)
        b = total - a
        print(abs(a - b))
