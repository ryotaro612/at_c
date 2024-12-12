n, m = map(int, input().split())
al = list(map(int, input().split()))
bl = list(map(int, input().split()))

res = [-1] * m
bv = sorted([b, i] for i, b in enumerate(bl))


for i, a in enumerate(al):
    while bv and a <= bv[-1][0]:
        res[bv.pop()[1]] = i + 1

for r in res:
    print(r)
