import math


def main():
    n = int(input())
    al = [int(c) for c in input()]

    res = solve(al)
    print(max(res))


def solve(al: list[int]) -> list[int]:
    """ """
    if len(al) == 1:
        if al[0]:
            return [1, 0]
        else:
            return [0, 1]

    n = len(al) // 3
    b0 = solve(al[:n])
    b1 = solve(al[n : 2 * n])
    b2 = solve(al[2 * n :])

    res = [math.inf] * 2
    for i in range(8):
        cnt = 0
        for j in range(3):
            if i & (1 << j):
                cnt += 1
        if cnt >= 2:
            bit = 1
        else:
            bit = 0
        res[bit] = min(res[bit], b0[(i >> 0) & 1] + b1[(i >> 1) & 1] + b2[(i >> 2) & 1])

    return res


main()
