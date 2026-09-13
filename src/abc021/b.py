import os
import sys
from collections import defaultdict, deque, Counter

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n = int(input())

a, b = map(int, input().split())

k = int(input())

pl = map(int, input().split())

counter = Counter(pl)

if [counter[k] for k in counter if counter[k] > 1]:
    print("NO")
    exit()

if a in counter or b in counter:
    print("NO")
    exit()

print("YES")
