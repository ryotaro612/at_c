# https://atcoder.jp/contests/abc445/tasks/abc445_d?lang=en
# 高さが同じグループを何個つくるれるか
import heapq

H, W, n = map(int, input().split())

hl, wl = [], []

heap_h, heap_w = [], []

for i in range(n):
    h, w = map(int, input().split())
    hl.append(h)
    wl.append(w)

    heapq.heappush(heap_h, (-h, w, i))
    heapq.heappush(heap_w, (-w, h, i))

res = [[-1, -1] for _ in range(n)]

top_l, top_r = 0, 0
cur_h, cur_w = H, W

while True:
    while heap_h and res[heap_h[0][2]][0] != -1:
        heapq.heappop(heap_h)
    while heap_w and res[heap_w[0][2]][0] != -1:
        heapq.heappop(heap_w)

    if not heap_h and not heap_w:
        break
    # print("res", res)
    # print("heap_h", heap_h)
    # print("heap_w", heap_w)
    # print("cur_h", cur_h, "cur_w", cur_w)
    # print("top_l", top_l, "top_r", top_r)
    # print("--")

    if -heap_h[0][0] == cur_h:
        h, w, i = heap_h[0]
        h = -h
        if h == cur_h:
            res[i] = [top_l + 1, top_r + 1]
            top_r += w
            top_r %= W
            cur_w -= w

    else:
        w, h, i = heap_w[0]
        w = -w
        assert w == cur_w
        res[i] = [top_l + 1, top_r + 1]
        top_l += h
        top_l %= H
        cur_h -= h


for r in res:
    print(r[0], r[1])
