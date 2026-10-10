import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


n, t  = map(int, input().split())

al = []
for _ in range(n):
    al.append(int(input()))


last = -10000000000000000000
res = 0
al = al[::-1]

for i in range(al[0] +  1):
    if i <= last + t:
        res += 1        
        # dbg(last, t, i, res)    
    if al and al[-1] == i:
        last = i        
        al.pop()



print(res + t)
            
        
