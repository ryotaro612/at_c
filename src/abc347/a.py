n, k = map(int, input().split())
al = list(map(int, input().split()))
res = [str(a // k) for a in al if a % k == 0]

print(" ".join(res))
