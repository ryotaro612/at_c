#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/**
 *  https://drken1215.hatenablog.com/entry/2018/06/08/210000
 */
template <ll P> class ModCombination {
public:
  int limit;
  /**
   * limit未満の(n, k)を計算できる。
   */
  ModCombination(int limit)
      : limit(limit), fac(limit), finv(limit), inv(limit) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < limit; i++) {
      fac[i] = fac[i - 1] * i % P;
      inv[i] = P - inv[P % i] * (P / i) % P;
      finv[i] = finv[i - 1] * inv[i] % P;
    }
  }

  ll compute_combination(int n, int k) {
    if (n < k)
      return 0;
    if (n < 0 || k < 0)
      return 0;
    return fac[n] * (finv[k] * finv[n - k] % P) % P;
  }

private:
  vector<ll> fac, finv, inv;
};

ll const mod = 998244353ll;
#ifdef ONLINE_JUDGE
int main() {
  ll d;
  cin >> d;
  ModCombination<mod> combi(2000010);
  cout << combi.compute_combination(d + d - 1, d) << endl;

  return 0;
}
#endif
