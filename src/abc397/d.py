import os
import sys
import math

sys.setrecursionlimit(10**7)


def dbg(*args):
    if os.environ.get("ATCODER") == "1":
        print(*args)


n = int(input())

for a in range(1, 1000000):
    b = 4 * n - a**3
    if b < 0:
        continue

    c = 3 * a * b
    c_sqrt = int(math.sqrt(c))
    if c != c_sqrt**2:
        continue

    d = 3 * a**2 + c_sqrt
    if d % (6 * a) == 0 and d // (6 * a) > 0:
        x = d // (6 * a)
        if x - a > 0:
            print(x, x - a)
            sys.exit(0)

    d = 3 * a**2 - c_sqrt
    if d % (6 * a) == 0 and d // (6 * a) > 0:
        x = d // (6 * a)
        if x - a > 0:
            print(x, x - a)
            sys.exit(0)

print(-1)
