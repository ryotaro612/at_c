import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, q = map(int, input().split())


lines = [["", list()]]


pcs = [0 for _ in range(n)]
server = 0

for _ in range(q):
    query = input().split()
    p = int(query[1]) - 1
    if query[0] == "1":
        pcs[p] = server
    elif query[0] == "2":
        lines[pcs[p]][1].append(len(lines))
        lines.append([query[2], list()])
        pcs[p] = len(lines) - 1
    else:
        server = pcs[p]


def rec(server, lines, path):
    if path[-1] == server:
        return True, "".join([lines[i][0] for i in path])

    for child in lines[path[-1]][1]:
        path.append(child)
        found, res = rec(server, lines, path)
        if found:
            return True, res
        path.pop()
    return False, ""


dbg(server)
dbg(lines)
dbg(pcs)
print(rec(server, lines, [0])[1])
