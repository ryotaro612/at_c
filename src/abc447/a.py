n, m = map(int, input().split())

cnt = 0
for i in range(0, n, 2):
    cnt += 1

if cnt < m:
    print("No")
else:
    print("Yes")
