#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  vector<vector<ll>> grid(n, vector<ll>(n));
  rep(i, n) {
    rep(j, n) { grid[i][j] = sv[i][j] - '0'; }
  }
  vector<pair<int, int>> deltas = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                   {0, 1},   {1, -1}, {1, 0},  {1, 1}};
  ll res = 0ll;
  rep(i, n) {
    rep(j, n) {
      for (auto [r, c] : deltas) {
        int row = i, col = j;
        ll temp = grid[row][col];
        rep(k, n - 1) {
          row = (row + n + r) % n;
          col = (col + n + c) % n;
          temp = temp * 10ll + (ll)grid[row][col];
        }
        res = max(res, temp);
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
/*
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(n, -1ll)));
  rep(k, n) {
    rep(i, n) {
      rep(j, n) {
        if (k == 0) {
          dp[i][j][0] = grid[i][j];
        } else {
          ll child = -1ll;
          vector<int> rows = {(i + n - 1) % n, i, (i + 1) % n};
          vector<int> cols = {(j + n - 1) % n, j, (j + 1) % n};
          for (int row : rows) {
            for (int col : cols) {
              if (row != i || col != j) {
                child = max(child, dp[row][col][k - 1]);
                string s = to_string(child);
                dp[i][j][k] = stoll(to_string(grid[i][j]) + s);
              }
            }
          }
        }
        cout << i << " " << j << " " << k << " -> " << dp[i][j][k] << endl;
      }
    }
  }

  ll res = 0ll;
  rep(i, n) {
    rep(j, n) { res = max(res, dp[i][j][n - 1]); }
  }
  cout << res << endl;

*/
