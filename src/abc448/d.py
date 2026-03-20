from collections import defaultdict

n = int(input())
al = [a for a in map(int, input().split())]
g = [[] for _ in range(n)]
# print(al)
for i in range(n - 1):
    u, v = map(int, input().split())
    g[u - 1].append(v - 1)
    g[v - 1].append(u - 1)

res = ["No" for _ in range(n)]


def traverse(node, parent, g, al, found, res):

    if found[al[node]] or (parent >= 0 and res[parent] == "Yes"):
        res[node] = "Yes"

    found[al[node]] += 1
    for child in g[node]:
        if child == parent:
            continue
        traverse(child, node, g, al, found, res)

    found[al[node]] -= 1


traverse(0, -1, g, al, defaultdict(int), res)


for e in res:
    print(e)
