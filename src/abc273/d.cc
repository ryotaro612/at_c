#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll move_backward(vector<ll> &walls, ll pos, ll delta, ll mx) {
  if (walls.empty() || walls[0] != 0) {
    walls.push_back(0);
    walls.push_back(mx + 1);
    sort(walls.begin(), walls.end());
  }
  auto wall = lower_bound(walls.begin(), walls.end(), pos);
  return max(*(wall - 1) + 1ll, pos - delta);
}

ll move_forward(vector<ll> &walls, ll pos, ll delta, ll mx) {
  if (walls.empty() || walls[0] != 0) {
    walls.push_back(0);
    walls.push_back(mx + 1);
    sort(walls.begin(), walls.end());
  }
  auto wall = lower_bound(walls.begin(), walls.end(), pos);
  return min(pos + delta, *wall - 1ll);
}

#ifdef ONLINE_JUDGE
int main() {
  ll h, w, rs, cs;
  cin >> h >> w >> rs >> cs;
  int n;
  cin >> n;
  vector<ll> rv(n), cv(n);
  rep(i, n) cin >> rv[i] >> cv[i];
  int q;
  cin >> q;
  vector<char> dv(q);
  vector<ll> lv(q);
  rep(i, q) cin >> dv[i] >> lv[i];

  map<ll, vector<ll>> row_cols, col_rows;
  rep(i, n) {
    row_cols[rv[i]].push_back(cv[i]);
    col_rows[cv[i]].push_back(rv[i]);
  }
  for (auto &v : row_cols) {
    sort(v.second.begin(), v.second.end());
    row_cols[v.first] = v.second;
  }
  for (auto &v : col_rows) {
    sort(v.second.begin(), v.second.end());
    col_rows[v.first] = v.second;
  }

  rep(i, q) {
    // cout << "q " << i << endl;
    char d = dv[i];
    ll l = lv[i];
    if (d == 'L') {
      cs = move_backward(row_cols[rs], cs, l, w);
    } else if (d == 'R') {
      cs = move_forward(row_cols[rs], cs, l, w);
    } else if (d == 'U') {
      rs = move_backward(col_rows[cs], rs, l, h);
    } else if (d == 'D') {
      rs = move_forward(col_rows[cs], rs, l, h);
    } else
      assert(false);
    cout << rs << " " << cs << endl;
  }

  return 0;
}
#endif
