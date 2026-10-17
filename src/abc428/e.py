import os
import sys
from collections import defaultdict, deque
import heapq

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())

g = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)


dist = [dict() for _ in range(n)]


def rec(node, g, dist, parent):

    res_dist = 0
    res_node = node

    for child in g[node]:
        if child == parent:
            continue
        a, b = rec(child, g, dist, node)
        dist[node][child] = (a + 1, b)
        if res_dist < a + 1:
            res_dist = a + 1
            res_node = b
        elif res_dist == a + 1:
            res_node = max(res_node, b)

    return res_dist, res_node


rec(0, g, dist, -1)

res = [-1] * n

dbg("dist", dist)


def rec2(node, dist, res, a_dist, a_node):

    top2 = sorted(
        [(dist[node][child][0], dist[node][child][1], child) for child in dist[node]]
    )[::-1][:2]

    dbg("node", node, dist, a_dist, a_node, top2)
    res[node] = max([(a_dist, a_node, -1)] + top2)[1]

    for child in dist[node]:
        if res[child] != -1:
            continue
        cand_node = a_node
        cand_dist = a_dist + 1
        if top2[0][2] == child:
            if len(top2) > 1:
                if cand_dist < top2[1][0] + 2:
                    cand_node = top2[1][1]
                    cand_dist = top2[1][0] + 2
                elif cand_dist == top2[1][0] + 2:
                    cand_node = max(cand_node, top2[1][1])
        else:
            if cand_dist < top2[0][0] + 2:
                cand_node = top2[0][1]
                cand_dist = top2[0][0] + 2
            elif cand_dist == top2[0][0] + 2:
                cand_node = max(cand_node, top2[0][1])

        rec2(child, dist, res, cand_dist, cand_node)


top2 = sorted([(d, descendant, child) for child, (d, descendant) in dist[0].items()])[
    ::-1
][:2]
dbg("top2", top2)
res[0] = top2[0][1]

for child, (d, descendant) in dist[0].items():
    sibling = (top2[0][0] + 2, top2[0][1], top2[0][2])
    if child == sibling[2]:
        if len(top2) > 1:
            sibling = (top2[1][0] + 2, top2[1][1], top2[1][2])
        else:
            sibling = (1, 0, 0)

    rec2(child, dist, res, sibling[0], sibling[1])


# rec2(0, g, dist, res, -(1 << 60), -1)

for v in res:
    print(v + 1)
