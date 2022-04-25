#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll compute_min(int t) { return 1ll << t; }

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> tv(n);
  rep(i, n) cin >> tv[i];

  ll cur = compute_min(tv[0]);
  for (int i = 1; i < n; i++) {
    ll t = compute_min(tv[i]);
    if (cur < t)
      cur = t;
    else { // t <= cur
      ll temp = ~0;
      rep(j, tv[i]) { temp >>= 1; }
      rep(j, tv[i]) { temp <<= 1; }
      cur &= temp;
      cur += t;
      cur |= t;
    }
  }
  cout << cur << endl;

  return 0;
}
//#endif
