#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<string> solve(int n, vector<ll> &av, vector<ll> &bv, int q,
                     vector<int> &xv, vector<int> &yv) {
  // unordered_map<ll, int> a_val_to_pos, b_val_to_pos;
  map<ll, int> a_val_to_pos, b_val_to_pos;
  rep(i, n) {
    if (a_val_to_pos.find(av[i]) == a_val_to_pos.end())
      a_val_to_pos[av[i]] = i;
    if (b_val_to_pos.find(bv[i]) == b_val_to_pos.end())
      b_val_to_pos[bv[i]] = i;
  }
  vector<int> a_limits(n, n), b_limits(n, n);
  rep(i, n) {
    if (b_val_to_pos.find(av[i]) != b_val_to_pos.end()) {
      if (i == 0) {
        a_limits[i] = b_val_to_pos[av[i]];
      } else {
        a_limits[i] = max(a_limits[i - 1], b_val_to_pos[av[i]]);
      }
    }

    if (a_val_to_pos.find(bv[i]) != a_val_to_pos.end()) {
      if (i == 0) {
        b_limits[i] = a_val_to_pos[bv[i]];
      } else {
        b_limits[i] = max(b_limits[i - 1], a_val_to_pos[bv[i]]);
      }
    }
  }
  // rep(i, n) cout << a_limits[i] << " ";
  // cout << endl;
  // rep(i, n) cout << b_limits[i] << " ";
  // cout << endl;
  vector<string> res;
  rep(i, q) {
    --xv[i];
    --yv[i];
    // cout << i << " -> " << b_limits[yv[i]] << " " << a_limits[xv[i]] << endl;
    if (b_limits[yv[i]] <= xv[i] && a_limits[xv[i]] <= yv[i])
      res.push_back("Yes");
    else
      res.push_back("No");
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n), bv(n);
  rep(i, n) { cin >> av[i]; }
  rep(i, n) { cin >> bv[i]; }
  int q;
  cin >> q;
  vector<int> xv(q), yv(q);
  rep(i, q) { cin >> xv[i] >> yv[i]; }
  vector<string> res = solve(n, av, bv, q, xv, yv);
  for (string e : res)
    cout << e << endl;
  return 0;
}
#endif
