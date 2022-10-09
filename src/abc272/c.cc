#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  set<ll> evens, odds;
  rep(i, n) {
    ll a;
    cin >> a;
    if (a % 2)
      odds.insert(a);
    else
      evens.insert(a);
  }
  ll res = -1ll;
  if (odds.size() > 1) {
    auto iter = odds.rbegin();
    res = *iter + *(++iter);
  }
  if (evens.size() > 1) {
    auto iter = evens.rbegin();
    res = max(res, *iter + *(++iter));
  }
  cout << res << endl;

  return 0;
}
#endif
