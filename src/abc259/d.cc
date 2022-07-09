#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ld compute_dist(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool is_on(ld sx, ld sy, ld x, ld y, ld r) {
  // return r * r == (sx - x) * (sx - x) + (sy - y) * (sy - y);
  return r * r == compute_dist(sx, sy, x, y);
}

string solve(int n, ld sx, ld sy, ld tx, ld ty, vector<ld> &xv, vector<ld> &yv,
             vector<ld> &rv) {
  int start = -1, goal = -1;
  rep(i, n) {
    if (is_on(sx, sy, xv[i], yv[i], rv[i])) {
      start = i;
    }
    if (is_on(tx, ty, xv[i], yv[i], rv[i])) {
      goal = i;
    }
  }
  vector<bool> reach(n, false);
  reach[start] = true;
  queue<int> que;
  que.push(start);
  // cout << start << " " << goal << endl;
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    rep(j, n) {
      if (i != j && reach[j] == false) {
        // cout << j << " " << j << " -> " << compute_dist(xv[i], yv[i], xv[j],
        // yv[j]) << endl;
        ld d = compute_dist(xv[i], yv[i], xv[j], yv[j]);
        if ((rv[i] - rv[j]) * (rv[i] - rv[j]) <= d &&
            d <= (rv[i] + rv[j]) * (rv[i] + rv[j])) {
          reach[j] = true;
          que.push(j);
        }
      }
    }
  }
  // rep(i, n) cout << reach[i] << " ";
  // cout << endl;

  if (reach[goal]) {
    return "Yes";
  } else {
    return "No";
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ld sx, sy, tx, ty;
  cin >> n >> sx >> sy >> tx >> ty;
  vector<ld> xv(n), yv(n), rv(n);
  rep(i, n) cin >> xv[i] >> yv[i] >> rv[i];
  cout << solve(n, sx, sy, tx, ty, xv, yv, rv) << endl;
  return 0;
}
#endif
