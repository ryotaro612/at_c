from typing import Self
import math


class ModInt:
    def __init__(self, v, mod):
        self.v = v
        self.mod = mod

    def __add__(self, other: Self):
        self._validate_mod(other)

        return ModInt((self.v + other.v) % self.mod, self.mod)

    def __sub__(self, other: Self):
        self._validate_mod(other)

        a = self.v - other.v
        if a < 0:
            a += self.mod
        return ModInt(a, self.mod)

    def __mul__(self, other: Self):
        self._validate_mod(other)

        return ModInt((self.v * other.v) % self.mod, self.mod)

    def __floordiv__(self, other: Self):
        self._validate_mod(other)

        g, x, _ = self._extgcd(other.v, self.mod)
        if g != 1:
            raise ValueError("Inverse does not exist")
        else:
            return ModInt(self.v * x % self.mod, self.mod)

    def _extgcd(self, a, b):
        if b == 0:
            return (a, 1, 0)
        else:
            g, x, y = self._extgcd(b, a % b)
            return (g, y, x - (a // b) * y)

    def _validate_mod(self, other: Self):
        if self.mod != other.mod:
            raise ValueError("Moduli must be the same")


MOD: int = 998244353


def solve(al: list[int]) -> list[int]:
    n = len(al)
    left = [ModInt(0, MOD) for _ in range(n)]
    right = [ModInt(0, MOD) for _ in range(n)]
    left_denom = [0] * n
    right_denom = [0] * n

    for i in range(n):
        if i == 0:
            left[0] = ModInt(al[0], MOD)
            right[n - 1] = ModInt(al[n - 1], MOD)
            left_denom[0] = al[0]
            right_denom[n - 1] = al[n - 1]
        else:
            left[i] = left[i - 1] * ModInt(al[i], MOD)
            right[n - 1 - i] = right[n - i] * ModInt(al[n - 1 - i], MOD)
            left_denom[i] = math.gcd(al[i], left_denom[i - 1])
            right_denom[n - 1 - i] = math.gcd(al[n - 1 - i], right_denom[n - i])

    res = [0] * n
    for i in range(n):
        if i == 0:
            print(right[1].v, ModInt(right_denom[1], MOD).v)
            res[0] = (right[1] // ModInt(right_denom[1], MOD)).v
        elif i == n - 1:
            res[n - 1] = (left[n - 2] // ModInt(left_denom[n - 2], MOD)).v
        else:
            res[i] = (
                (left[i - 1] * right[i + 1])
                // (ModInt(left_denom[i - 1], MOD) * ModInt(right_denom[i + 1], MOD))
            ).v

    return res


for _ in range(int(input())):
    input()
    al = list(map(int, input().split()))
    print(" ".join(map(str, solve(al))))
