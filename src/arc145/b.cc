#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

/**
   n < aならAliceは必ず負ける
   以下はa <= nのとき
   a <= bのときは必ず勝つ。最初にとりつくす。
   b < a のとき
   n % a < bであれば勝つ。
 */
ll solve(ll n, ll a, ll b) {
  if (n < a) {
    return 0ll;
  }
  // a <= n
  if (a <= b) {
    return n - a + 1ll;
  }
  // a <= n && b < a
  else {
    ll res = n / a * b - b + 1ll;
    ll remain = n - n / a * a;
    // cout << res << " remain: " << remain << endl;
    if (remain == 0ll)
      return res;
    else if (b <= remain) {
      // cout << "doge " << res << " remain " << remain << endl;
      return res + b - 1ll;
    } else { // remain < b
      // cout << "bar" << endl;
      return res + remain;
    }
  }
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << solve(n, a, b) << endl;
  return 0;
}
#endif
