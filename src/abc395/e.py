import math
import heapq

n, m, x = list(map(int, input().split()))

ul = []
vl = []

g = [[[], []] for _ in range(n)]

for _ in range(m):
    u, v = list(map(int, input().split()))
    u -= 1
    v -= 1
    g[u][0].append(v)
    g[v][1].append(u)

d = [[math.inf, math.inf] for _ in range(n)]

d[0][0] = 0

heap = [(0, 0, 0)]

while heap:
    cost, flip, node = heapq.heappop(heap)

    if d[node][flip] < cost:
        continue

    if d[node][flip ^ 1] > cost + x:
        d[node][flip ^ 1] = cost + x
        heapq.heappush(heap, (d[node][flip ^ 1], flip ^ 1, node))

    for s_node in g[node][flip]:
        new_cost = cost + 1
        if d[s_node][flip] > new_cost:
            d[s_node][flip] = new_cost
            heapq.heappush(heap, (new_cost, flip, s_node))

print(min(d[n - 1]))
