n, k = map(int, input().split())
al = list(map(int, input().split()))

a_mx = max(al)

res = float('inf')
for i in range(n):
    diff = a_mx - al[i]
    al[i] += diff // k * k
    res = min(res, a_mx - al[i])

