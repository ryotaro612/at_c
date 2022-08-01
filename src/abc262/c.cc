#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, vector<ll> &av) {
  map<ll, ll> counter;
  counter[av[0]]++;
  ll same_c = 0;
  if (av[0] == 1ll)
    same_c++;
  ll res = 0ll;
  for (ll j = 1ll; j < n; j++) {
    // a_j == i, a_i == j
    if (av[j] < j + 1ll) {
      if (av[av[j] - 1] == j + 1)
        res++;
      // res += counter[j + 1];
    }
    if (av[j] == j + 1ll) {
      res += same_c;
      same_c++;
    }

    counter[av[j]] += 1ll;
    // cout << j << " res: " << res << " same_c " << same_c << endl;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;
  return 0;
}
#endif
