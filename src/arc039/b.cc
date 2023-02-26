#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)
const ll MAX = 510000;
const ll MOD = 1000000007ll;

long long fac[MAX], finv[MAX], inv[MAX];

/**
 *  https://drken1215.hatenablog.com/entry/2018/06/08/210000
 */
class ModCombination {
public:
  ll mod;
  int limit;

  ModCombination(ll mod, int limit)
      : mod(mod), limit(limit), fac(limit), finv(limit), inv(limit) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
  }

  ll compute_combination(int n, int k) {
    if (n < k)
      return 0;
    if (n < 0 || k < 0)
      return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  }

private:
  vector<ll> fac, finv, inv;
};

#ifdef ONLINE_JUDGE
int main() {

  ll n, k;
  cin >> n >> k;
  ModCombination combinator(MOD, MAX);
  if (k < n) {
    cout << combinator.compute_combination(n - 1 + k, k) << endl;
  } else
    cout << combinator.compute_combination(n, k % n) << endl;

  return 0;
}
#endif
