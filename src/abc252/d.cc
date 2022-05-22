#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(int n, vector<int> &av) {
  unordered_map<int, int> counter;
  rep(i, n) { counter[av[i]]++; }
  ll res = ((ll)n * (ll)(n - 1ll) * (ll)(n - 2ll)) / 6ll;
  for (auto [_, num] : counter) {
    if (num >= 3) {
      res -= ((ll)num * (ll)(num - 1ll) * (ll)(num - 2ll)) / 6ll;
    }
  }
  for (auto [_, num] : counter) {
    if (num >= 2) {
      ll temp = ((ll)num * (ll)(num - 1ll)) / 2ll;
      temp *= n - num;
      res -= temp;
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;
  return 0;
}
#endif
