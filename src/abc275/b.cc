#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
const ll MOD = 998244353ll;

#ifdef ONLINE_JUDGE
int main() {
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  ll result = a % MOD;
  result *= b % MOD;
  result %= MOD;
  result *= c % MOD;
  result %= MOD;
  ll sub = d % MOD;
  sub *= e % MOD;
  sub %= MOD;
  sub *= f % MOD;
  sub %= MOD;
  result -= sub;
  if (result < 0)
    result += MOD;
  cout << result << endl;

  return 0;
}
#endif
