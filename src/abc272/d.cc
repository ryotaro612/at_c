#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll m;
  cin >> n >> m;
  const ll inf = 10000000000ll;
  vector<vector<ll>> d(n, vector<ll>(n, inf));
  d[0][0] = 0ll;
  priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>,
                 greater<pair<ll, pair<int, int>>>>
      que;

  que.push({0, {0, 0}});
  while (que.size()) {
    pair<ll, pair<int, int>> item = que.top();
    ll dist = item.first;
    auto [i, j] = item.second;
    que.pop();
    if (d[i][j] < dist)
      continue;

    for (int k = 1; k <= n; k++) {
      // m - (i - k) * (i-k) == (j - l) * (j-l);
      ll goal = m - ((i + 1) - k) * ((i + 1) - k);
      if (goal >= 0) {
        ll lb = 0, ub = 401;
        while (ub - lb > 1) {
          ll mid = (lb + ub) / 2ll;
          if (goal < mid * mid)
            ub = mid;
          else
            lb = mid;
        }
        // cout << i << " " << j << " " << k << " " << lb << endl;
        if (lb * lb != goal)
          continue;
        int l = (j + 1) - lb;
        if (1 <= l && l <= n && dist + 1 < d[k - 1][l - 1]) {
          d[k - 1][l - 1] = dist + 1;
          que.push({d[k - 1][l - 1], {k - 1, l - 1}});
        }
        l = lb + (j + 1);
        if (1 <= l && l <= n && dist + 1 < d[k - 1][l - 1]) {
          d[k - 1][l - 1] = dist + 1;
          que.push({d[k - 1][l - 1], {k - 1, l - 1}});
        }
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      cout << (d[i][j] == inf ? -1 : d[i][j]);
      if (j == n - 1)
        cout << endl;
      else
        cout << " ";
    }
  }
  return 0;
}
//#endif
