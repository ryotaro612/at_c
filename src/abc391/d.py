import math


def main():
    n, w = list(map(int, input().split()))
    # print(n, w)
    xl = []
    yl = []
    for _ in range(n):
        x, y = list(map(int, input().split()))
        xl.append(x - 1)
        yl.append(y)

    q = int(input())
    tl = []
    al = []
    for _ in range(q):
        t, a = list(map(int, input().split()))
        tl.append(t)
        al.append(a - 1)

    wl = [[] for _ in range(w)]

    for i in range(n):
        wl[xl[i]].append((yl[i], i))

    remove_times = dict()

    height = 0
    while True:
        ok = True
        for i in range(w):
            if len(wl[i]) <= height:
                ok = False
                break

        # print(height, ok)
        if ok:
            mx = 0
            for i in range(w):
                mx = max(mx, wl[i][height][0])
            for i in range(w):
                remove_times[wl[i][height][1]] = mx
            height += 1
        else:
            break

    for i in range(q):
        if remove_times.get(al[i], math.inf) > tl[i]:
            print("Yes")
        else:
            print("No")


main()
