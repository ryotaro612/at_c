import os
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**7)


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


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


MOD = 998244353

a, b, c, d = map(int, input().split())

combi = Combi(a + b + c + d + 1, MOD)


res: ModInt = ModInt(0, MOD)
for i in range(a, a + b + 1):
    orange = b - (i - a)
    left = combi.comb(i - 1, a - 1)
    right = combi.comb(orange + c + d, c)
    temp = left * right
    # dbg(
    #     i, "left", left, "right", right, "total", orange + c + d, "orange", orange, temp
    # )
    res += temp

print(res)
