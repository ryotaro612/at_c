import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))



n, s, t = map(int, input().split())

w  = int(input())

res = 0
if s <= w <= t:
    res += 1


for _ in range(n-1):
    w += int(input())
    
    if s <= w <= t:
        res += 1

print(res)
    
    
