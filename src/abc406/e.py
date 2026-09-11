import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


class ModInt:
    def __init__(self, v, mod):
        self.v = v % mod
        self.mod = mod

    def __mul__(self, other):
        self._validate(other)
        return ModInt(self.v * other.v % self.mod, self.mod)

    def __add__(self, other):
        self._validate(other)
        return ModInt((self.v + other.v) % self.mod, self.mod)

    def __truediv__(self, other):
        self._validate(other)
        return ModInt(self.v * other._modinv() % self.mod, self.mod)

    def _modinv(self):
        return self._ext_gcd(self.v, self.mod)[1] % self.mod

    def __repr__(self):
        return str(self.v)

    def _ext_gcd(self, a, b):
        if b == 0:
            return a, 1, 0
        else:
            g, x, y = self._ext_gcd(b, a % b)
            return g, y, x - (a // b) * y

    def _validate(self, other):
        if not isinstance(other, ModInt):
            raise TypeError(
                "Unsupported operand type(s) for operation: 'ModInt' and '{}'".format(
                    type(other).__name__
                )
            )
        if self.mod != other.mod:
            raise ValueError("Cannot operate on ModInt with different mod values")


class Combi:
    def __init__(self, n, mod):
        self.mod = mod
        self.n = n
        self.memo = [ModInt(1, mod) for _ in range(n)]
        for i in range(1, n):
            self.memo[i] = self.memo[i - 1] * ModInt(i, mod)

    def comb(self, n, r) -> ModInt:
        if r < 0 or r > n:
            return ModInt(0, self.mod)

        return self.memo[n] / (self.memo[r] * self.memo[n - r])


def sub(n: int, k: int, mod_int: int):
    l = 0
    while (1 << l) <= n:
        l += 1
    # lはnの最左ビット位置+1
    # OK
    res = ModInt(0, mod_int)
    dbg("l", l)
    for a in range(l):
        dp = [
            [[ModInt(0, mod_int) for _ in range(k + 2)] for _ in range(2)]
            for _ in range(l + 1)
        ]

        dp[l][0][0] = ModInt(1, mod_int)
        for b in range(l - 1, -1, -1):
            for c in range(min(k + 1, l - b + 1)):
                if (1 << b) & n:
                    if a == b:
                        dp[b][0][c + 1] += dp[b + 1][0][c]
                        dp[b][1][c + 1] += dp[b + 1][1][c]
                    else:
                        dp[b][0][c + 1] += dp[b + 1][0][c]
                        dp[b][1][c] += dp[b + 1][0][c]
                        dp[b][1][c + 1] += dp[b + 1][1][c]
                        dp[b][1][c] += dp[b + 1][1][c]
                else:
                    if a == b:
                        dp[b][1][c + 1] += dp[b + 1][1][c]
                    else:
                        dp[b][0][c] += dp[b + 1][0][c]
                        dp[b][1][c + 1] += dp[b + 1][1][c]
                        dp[b][1][c] += dp[b + 1][1][c]
        # print("a", a)
        # print("dp0", dp[0][0][k])
        # print("dp1", dp[0][1][k])
        res += (dp[0][0][k] + dp[0][1][k]) * ModInt(1 << a, mod_int)

    return res


t = int(input())


for _ in range(t):
    n, k = map(int, input().split())
    print(sub(n, k, 998244353))
