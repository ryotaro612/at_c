#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll const MOD = 998244353ll;

long long modinv(long long a, long long m = MOD) {
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
ll divmod(ll a, ll b) { return a * modinv(b) % MOD; }

ll com(ll a, ll b) {
  ll child = 1ll;
  rep(i, b) {
    child *= (i + 1ll);
    child %= MOD;
  }
  ll parent = 1ll;
  rep(i, b) {
    parent *= (a - i);
    parent %= MOD;
  }
  // cout << a << " " << b << " " << child << " " << parent << endl;
  return divmod(parent, child);
}

bool is_ok(int n, int k, vector<ll> &av) {
  ll temp = 0ll;
  for (int i = 1; i < n; i++) {
    temp += av[i];
    if (av[0] + k < temp) {
      return false;
    }
  }
  return true;
}

ll solve(int n, int k, vector<ll> &av) {
  if (!is_ok(n, k, av))
    return 0;
  ll no_one_sum = 0ll;
  for (int i = 1; i < n; i++) {
    no_one_sum += av[i];
    no_one_sum %= MOD;
  }

  ll temp = av[0] - 1ll - no_one_sum;
  ll res = com(temp, k - 1ll);
  for (int i = 1; i < n; i++) {
    res *= com(((av[i] + k) % MOD - 1ll) % MOD, k - 1ll);
    res %= MOD;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  cout << solve(n, k, av) << endl;
  return 0;
}
