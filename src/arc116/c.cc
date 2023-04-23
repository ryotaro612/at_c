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
ll const mod = 998244353ll;

vector<pair<ll, int>> prime_factorization(ll n) {
  vector<pair<ll, int>> res;
  for (ll i = 2ll; i * i <= n; i++) {
    if (n % i)
      continue;
    int count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    res.push_back({i, count});
  }
  if (n != 1)
    res.push_back({n, 1});

  return res;
}

/**
 *  https://drken1215.hatenablog.com/entry/2018/06/08/210000
 */
template <ll P> class ModCombination {
public:
  int limit;

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

//#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  ModCombination<mod> combi(200100);
  ll res = 0ll;
  for (ll i = 1; i <= m; i++) {
    vector<pair<ll, int>> prime_factors = prime_factorization(i);
    ll count = 1ll;
    for (auto [_, freq] : prime_factors) {
      count *= combi.compute_combination(n - 1 + freq, freq);
      count %= mod;
    }
    res += count;
    res %= mod;
  }
  cout << res << endl;

  return 0;
}
//#endif
