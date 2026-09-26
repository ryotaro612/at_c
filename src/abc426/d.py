import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())


def solve(s: list[int]):
    dbg("s", s)
    if len(set(s)) == 1:
        return 0

    n = len(s)
    prefix = [0] * (n + 1)
    prefix_0 = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + s[i]
        prefix_0[i + 1] = prefix_0[i] + (1 - s[i])

    one_idx = [i for i in range(n) if s[i]]

    if len(one_idx) == 1:
        # i = 2, n = 5
        # 00100
        #
        i = one_idx[0]
        cand1 = i * 2 + 1
        cand2 = 1 + (n - (i + 1)) * 2
        return min(cand1, cand2)

    i = one_idx[0]
    res = (prefix[n] - prefix[i]) + ((n - i) - (prefix[n] - prefix[i])) * 2

    for i, idx in enumerate(one_idx):
        if i < len(one_idx) - 1:
            cand1 = prefix[idx + 1] + (idx + 1 - prefix[idx + 1]) * 2
            cand2 = (prefix[n] - prefix[one_idx[i + 1]]) + (
                n - (one_idx[i + 1]) - (prefix[n] - prefix[one_idx[i + 1]])
            ) * 2
            dbg("idx", idx, "cand", cand1, "cand2", cand2)
            res = min(res, cand1 + cand2)

        else:
            cand = prefix[idx + 1] + (idx + 1 - prefix[idx + 1]) * 2
            dbg("idx", idx, "cand", cand)
            res = min(res, cand)

    return res


for _ in range(t):
    n = int(input())
    s = input()

    line = [int(c) for c in s]
    print(min(solve(line), solve([1 - c for c in line])))
