import sys
from bisect import bisect_right


def sieve(n: int) -> list[int]:
    """エラトステネスの篩を用いて n 未満の素数リストを生成する"""
    is_prime = [True] * n
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n, i):
                is_prime[j] = False
    return [i for i, prime in enumerate(is_prime) if prime]


def main():
    # 入力の高速化
    input = sys.stdin.read
    data = input().split()
    if not data:
        return

    # 素数の生成
    primes = sieve(500000)
    limit = 1000000000000  # 10^12

    found = set()
    num_primes = len(primes)

    # 条件を満たす値 (a * b <= limit) を全列挙
    for i in range(num_primes - 1):
        p_i = primes[i]
        step_a = p_i * p_i

        # 枝刈り: 最低でも step_a * (step_b の最小値) が limit を超えるなら打ち切り
        if step_a * (primes[i + 1] ** 2) > limit:
            break

        for j in range(i + 1, num_primes):
            p_j = primes[j]
            step_b = p_j * p_j

            a = step_a
            if a * step_b > limit:
                break

            while a * step_b <= limit:
                b = step_b
                while a * b <= limit:
                    found.add(a * b)
                    b *= step_b
                a *= step_a

    # 二分探索用にソート済みリストを用意
    s = sorted(found)

    # クエリ処理
    q = int(data[0])
    queries = [int(x) for x in data[1 : q + 1]]

    results = []
    for a_val in queries:
        # C++ の std::set::upper_bound(a) - 1 と同等の処理
        idx = bisect_right(s, a_val) - 1
        results.append(str(s[idx]))

    print("\n".join(results))


if __name__ == "__main__":
    main()
