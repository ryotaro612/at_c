import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


a, b, c = map(int, input().split())

if a + b == c:
    if a - b == c:
        print("?")
    else:
        print("+")
elif a - b == c:
    print("-")
else:
    print("!")
