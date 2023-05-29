#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(ll n) {
  if (n < 7)
    return -1ll;

  vector<ll> poss;
  for (ll i = 0; n >> i; i++) {
    if (n & (1ll << i))
      poss.push_back(i);
  }

  reverse(poss.begin(), poss.end());
  if (poss.size() > 2) {
    return (1ll << poss[0]) + (1ll << poss[1]) + (1ll << poss[2]);
  } else if (poss.size() == 2) {
    if (poss[1] <= 1) {
      return (1ll << (poss[0] - 1ll)) + (1ll << (poss[0] - 2ll)) +
             (1ll << (poss[0] - 3ll));
    } else {
      return (1ll << poss[0]) + (1ll << (poss[1] - 1ll)) +
             (1ll << (poss[1] - 2ll));
    }
  } else {
    return (1ll << (poss[0] - 1ll)) + (1ll << (poss[0] - 2ll)) +
           (1ll << (poss[0] - 3ll));
  }
}

#ifdef ONLINE_JUDGE
int main() {

  int t;
  cin >> t;
  rep(_, t) {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
#endif
