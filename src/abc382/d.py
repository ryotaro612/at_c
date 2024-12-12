import functools

n, m = map(int, input().split())


@functools.cache
def temp(i, threshold):
    res = []
    if i == n - 1:
        for v in range(threshold, m + 1):
            res.append([v])

        return res

    for v in range(threshold, m + 1):
        sub = temp(i + 1, v + 10)
        res.extend([[v] + s for s in sub])

    return res


res = temp(0, 1)

print(len(res))
for r in res:
    print(" ".join([str(a) for a in r]))
