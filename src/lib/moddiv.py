from typing import Self


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
