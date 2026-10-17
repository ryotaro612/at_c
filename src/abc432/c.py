import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, x, y = map(int, input().split())

al = list(map(int, input().split()))


if len(al) == 1:
    print(al[0])
    sys.exit(0)

diff = [0] * n

for i in range(1, n):
    dbg(i, al[0] - al[i], y - x)
    if (al[0] - al[i]) * x % (y - x) != 0:
        print(-1)
        sys.exit(0)

    diff[i] = (al[0] - al[i]) * x // (y - x)

offset = 0
for i in range(n):
    if al[i] < al[0] + diff[i]:
        offset = max(offset, al[0] + diff[i] - al[i])

fixed = [al[0] + diff[i] - offset for i in range(n)]

if min(fixed) < 0:
    print(-1)
    sys.exit(0)

print(sum(fixed))
