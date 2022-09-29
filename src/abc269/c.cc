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
  ll n;
  cin >> n;
  vector<int> bits;
  rep(i, 60) {
    if ((1ll << i) & n) {
      bits.push_back(i);
    }
  }
  vector<ll> res;
  rep(i, 1ll << bits.size()) {
    ll temp = 0ll;
    rep(j, bits.size()) {
      if (i & (1ll << j))
        temp |= 1ll << bits[j];
    }
    res.push_back(temp);
  }

  sort(res.begin(), res.end());
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
