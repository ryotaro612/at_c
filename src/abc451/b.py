n, m = map(int, input().split())
al, bl = [], []
c_ml = [0] * (m+1)
n_ml = [0] * (m+1)
for i in range(n):
    a, b = map(int, input().split())
    al.append(a)
    bl.append(b)
    c_ml[a-1] += 1
    n_ml[b-1] += 1

for i in range(m):
    print(n_ml[i] - c_ml[i])
    
