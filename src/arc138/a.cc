#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  map<ll, int> location;
  for (int i = n - 1; k <= i; i--) {
    location[av[i]] = i;
  }
  for (auto iter = location.rbegin(); iter != location.rend(); iter++) {
    if (iter != location.rbegin() && prev(iter)->second < iter->second) {
      location[iter->first] = prev(iter)->second;
    }
  }

  int res = numeric_limits<int>::max();
  rep(i, k) {

    auto iter = location.upper_bound(av[i]);
    if (iter == location.end())
      continue;
    int index = iter->second;
    res = min(k - 1 - i + index - k + 1, res);
    // 1 2 3 4 5 7 7
  }
  if (res == numeric_limits<int>::max())
    res = -1;
  cout << res << endl;
  return 0;
}
#endif
