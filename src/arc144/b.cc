#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, ll a, ll b, vector<ll> &av) {
  sort(av.begin(), av.end(), greater());

  ll lb = 0, ub = 1000000001ll;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2ll;
    ll count = 0ll;
    rep(i, n) {
      if (av[i] >= mid) {
        count += (av[i] - mid) / b;
      } else { // av[i] < mid
        ll required = (mid - av[i]) / a;
        if (av[i] + required * a < mid)
          required += 1;
        count -= required;
      }
    }
    if (count < 0) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return lb;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  ll a, b;
  cin >> a >> b;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, a, b, av) << endl;
  return 0;
}
#endif
