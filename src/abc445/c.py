n = int(input())

al = [int(a) - 1 for a in input().split()]


for i in range(n - 1, -1, -1):
    succ = al[i]
    while al[succ] != succ:
        succ = al[succ]
    al[i] = succ

print(*[a + 1 for a in al])
