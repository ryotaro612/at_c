#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll MOD = 998244353ll;

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
ll moddiv(ll a, ll b) { return a * modinv(b, MOD) % MOD; }

ll solve(ll n) {
  int keta = to_string(n).size();
  ll res = 0ll;
  for (int i = 0; i < keta - 1; i++) {
    ll d = 9;
    for (int j = 0; j < i; j++) {
      d *= 10ll;
      d %= MOD;
    }
    ll temp = moddiv(d, 2ll) * ((d + 1ll) % MOD) % MOD;
    res += temp;
    res %= MOD;
  }
  ll d = 1ll;
  for (int i = 0; i < keta - 1; i++) {
    d *= 10ll;
    d %= MOD;
  }
  ll temp = n - d;
  if (temp < 0)
    temp += MOD;
  temp += 1ll;
  temp %= MOD;

  res += moddiv(temp * ((temp + 1ll) % MOD) % MOD, 2ll);
  res %= MOD;
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
#endif
