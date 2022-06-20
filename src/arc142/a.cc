#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll rev(ll k) {
  ll rt = 0;
  while (k)
    rt = rt * 10 + k % 10, k /= 10;
  return rt;
}

int solve(ll n, ll k) {
  set<ll> res;
  ll kk = k;
  if (rev(k) < k)
    return 0;
  while (kk <= n) {
    if (kk <= n) {
      res.insert(kk);
      kk *= 10ll;
    }
  }
  // string ks = to_string(k);
  // revererse(ks.begin(), ks.end());
  kk = rev(k);
  while (kk <= n) {
    if (kk <= n) {
      res.insert(kk);
      kk *= 10ll;
    }
  }
  // for (auto e : res)
  //   cout << e << endl;
  return res.size();
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}
#endif
