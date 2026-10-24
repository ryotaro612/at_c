import os
import sys
from collections import defaultdict, deque, Counter

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, m, c = map(int, input().split())

al = sorted(
    [[idx, cnt] for idx, cnt in Counter(list(map(int, input().split()))).items()]
)


right = 0
cnt = 0
res = 0
for left, [pos, freq] in enumerate(al):
    while cnt < c:
        cnt += al[right][1]
        right += 1
        right %= len(al)

    if left == 0:
        # 0 1 2 3 4 5
        # m - al[-1] - 1
        delta = cnt * ((m - 1 - al[-1][0]) + pos + 1)
        res += delta
        dbg("left", left, "delta", delta)
        cnt -= freq
    else:
        delta = cnt * (pos - al[left - 1][0])
        res += delta
        dbg("left", left, "delta", delta)
        cnt -= freq

print(res)
