#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int sub(vector<int> av, vector<int> bv) {
  int n = av.size();

  vector<pair<int, int>> ab(n);
  rep(i, n) { ab[i] = {av[i], bv[i]}; }
  sort(ab.begin(), ab.end());
  rep(i, n) bv[i] = ab[i].second;
  int inf = 1000000;
  vector<int> dp(n, inf);

  rep(i, n) {
    auto iter = lower_bound(dp.begin(), dp.end(), bv[i]);
    *iter = bv[i];
  }
  return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf)) + n;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];

  cout << sub(av, bv) << endl;

  return 0;
}
#endif

/*
  for (int i = 0; i < n; i++) {
*lower_bound(dp, dp + n, a[i]) = a[i];
}
printf("%d¥n", lower_bound(dp, dp + n, INF) - dp);
*/
