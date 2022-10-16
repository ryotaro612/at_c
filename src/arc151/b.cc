#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

const ll MOD = 998244353ll;

int find_root(int i, vector<int> &par) {
  if (par[i] < 0)
    return i;
  return par[i] = find_root(par[i], par);
}
bool is_same_group(int a, int b, vector<int> &par) {
  return find_root(a, par) == find_root(b, par);
}

void unite(int a, int b, vector<int> &par) {
  if (is_same_group(a, b, par))
    return;

  int root_a = find_root(a, par), root_b = find_root(b, par);
  if (par[root_a] < par[root_b]) {
    par[root_a] += par[root_b];
    par[root_b] = root_a;
  } else {
    par[root_b] += par[root_a];
    par[root_a] = root_b;
  }
}

ll pow_mod(ll x, ll n) {
  ll res = 1ll;
  while (n > 0) {
    if (n & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> pv(n);
  rep(i, n) {
    cin >> pv[i];
    pv[i]--;
  }

  vector<int> par(n, -1);
  ll res = 0ll;
  int a = n;
  rep(i, n) {
    if (is_same_group(i, pv[i], par))
      continue;

    res += pow_mod(m, a - 2) * m % MOD * (m - 1ll) % MOD * modinv(2ll, MOD);
    a--;
    unite(i, pv[i], par);
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
#endif
