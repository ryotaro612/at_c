import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


t = int(input())

for x in range(t):
    dbg(x)
    n = int(input())
    s = input()
    if n == 1:
        print(s)
        continue

    for i in range(n - 1):
        if s[i] > s[i + 1]:
            for j in range(i + 1, n - 1):
                if s[i] < s[j + 1]:
                    print(s[:i] + s[i + 1 : j + 1] + s[i] + s[j + 1 :])
                    break
            else:
                print(s[:i] + s[i + 1 :] + s[i])
            break
    else:
        print(s)
