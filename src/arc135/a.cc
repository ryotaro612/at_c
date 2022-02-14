#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll const MOD = 998244353ll;

struct TwoThree {
  ll two, three;
};

unordered_map<ll, TwoThree> cache;

TwoThree sub(ll v) {
  if (cache.find(v) != cache.end())
    return cache[v];
  if (v == 2) {
    cache[v] = {1ll, 0};
    return cache[v];
  } else if (v == 3) {
    cache[v] = {0ll, 1ll};
    return cache[v];
  }
  ld divide = (ld)v / (ld)2ll;
  TwoThree a = sub(ceil(divide));
  TwoThree b = sub(floor(divide));
  TwoThree res = {a.two + b.two, a.three + b.three};
  cache[v] = res;
  return cache[v];
}

ll mod_fac(ll x, ll n) {
  ll res = 1ll;
  while (n > 0ll) {
    if (n & 1) {
      res *= x;
      res %= MOD;
    }
    n >>= 1;
    x *= x;
    x %= MOD;
  }
  return res;
}

ll solve(ll x) {
  if (x == 1)
    return x;

  TwoThree tt = sub(x);

  return mod_fac(2ll, tt.two) * mod_fac(3ll, tt.three) % MOD;
}

#ifdef ONLINE_JUDGE
int main() {
  ll x;
  cin >> x;
  cout << solve(x) << endl;
  return 0;
}
#endif
