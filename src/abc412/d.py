import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m = map(int, input().split())
# g = [set() for _ in range(n)]

# for _ in range(m):
#     a, b = map(int, input().split())

#     g[a - 1].add(b - 1)
#     g[b - 1].add(a - 1)

edges = set()
for _ in range(m):
    a, b = map(int, input().split())
    edges.add((min(a, b) - 1, max(a, b) - 1))


res = 1000000000000000


def order(rest: list[int], idx: int, cur: set[tuple[int, int]]):
    global res
    n = len(rest)
    if idx == n:
        a = cur - edges
        b = edges - cur
        res = min(res, len(a) + len(b))
        return

    if rest[idx] < 2:
        rest[idx] += 1
        for i in range(idx + 1, n):
            if rest[i] < 2 and (idx, i) not in cur:
                rest[i] += 1
                cur.add((idx, i))
                order(rest, idx, cur)
                cur.remove((idx, i))
                rest[i] -= 1
        rest[idx] -= 1
    else:
        order(rest, idx + 1, cur)


order([0 for _ in range(n)], 0, set())

print(res)
