def solve():
    n = int(input())
    al = list(map(int, input().split()))

    lb = -1
    ub = n // 2 + 1
    while ub - lb > 1:
        mid = (lb + ub) // 2

        ok = True
        j = 0
        for i in range(mid - 1, -1, -1):
            if al[i] * 2 > al[n - 1 - j]:
                ok = False
                break
            j += 1
        if ok:
            lb = mid
        else:
            ub = mid

    print(lb)


solve()
