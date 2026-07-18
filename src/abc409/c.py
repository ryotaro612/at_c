import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, l = map(int, input().split())
dv = list(map(int, input().split()))
dbg(dv)
if l % 3 != 0:
    print(0)
    exit()


circle = defaultdict(int)
circle[0] = 1
pos = 0
for i in range(n - 1):
    d = dv[i]
    pos = (pos + d) % l
    circle[pos] += 1


points = sorted(circle.keys())
res = 0
trip = l // 3
for point in points:
    if point + trip * 2 > l:
        break

    res += circle[point] * circle[point + trip] * circle[point + trip * 2]


print(res)
