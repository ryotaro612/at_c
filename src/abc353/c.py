import os
import sys

sys.setrecursionlimit(10**7)


def dbg(*args):
    if os.environ.get("ATCODER") != "1":
        print(*args)


n = int(input())

al = list(map(int, input().split()))

al.sort()

MOD = 100000000

prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + al[i]


res = 0
j = n
for i in range(n - 1):
    while j > i + 1 and al[j - 1] + al[i] >= MOD:
        # dbg("dec", j - 1, i, al[j - 1], al[i])
        j -= 1
    #
    res += al[i] * (n - 1 - i)
    res += prefix[n] - prefix[i + 1]
    res -= MOD * (n - max(i + 1, j))
    dbg("dec", i, j, n - j)


print(res)
