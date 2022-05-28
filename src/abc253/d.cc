#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
/*  lcm (a, b) : 2整数版
    入力：整数 a, b
    出力：aとbの最小公倍数
*/
long long lcm(long long a, long long b) {
  long long d = gcd(a, b);
  return a / d * b;
}

ll sub(ll n, ll a) {
  ll num = n / a;
  ll mx = num * a;
  if (num % 2ll == 0ll) {
    return (a + mx) * num / 2ll;
  } else {
    return (a + mx) * (num - 1ll) / 2ll + (a + mx) / 2ll;
  }
}

ll solve(ll n, ll a, ll b) {
  ll sum;
  if (n % 2ll == 0ll) {
    sum = (n + 1ll) * n / 2ll;
  } else
    sum = (n + 1ll) * (n - 1ll) / 2ll + (n + 1ll) / 2ll;

  return sum - sub(n, a) - sub(n, b) + sub(n, lcm(a, b));
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << solve(n, a, b) << endl;
  return 0;
}
#endif
