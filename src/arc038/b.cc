#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

bool solve(int r, int c, vector<string> &sm, vector<vector<int>> &dp) {
  if (dp[r][c] != -1)
    return dp[r][c];
  int n_row = sm.size(), n_col = sm[0].size();
  if (r < n_row - 1 && sm[r + 1][c] == '.') {
    if (!solve(r + 1, c, sm, dp))
      return dp[r][c] = 1;
  }
  if (c < n_col - 1 && sm[r][c + 1] == '.') {
    if (!solve(r, c + 1, sm, dp))
      return dp[r][c] = 1;
  }
  if (r < n_row - 1 && c < n_col - 1 && sm[r + 1][c + 1] == '.') {
    if (!solve(r + 1, c + 1, sm, dp))
      return dp[r][c] = 1;
  }

  return dp[r][c] = 0;
}

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sm(h);
  rep(i, h) cin >> sm[i];
  // dp[i][j] == 1 First == 0 Second;
  vector<vector<int>> dp(h, vector<int>(w, -1));

  if (solve(0, 0, sm, dp))
    cout << "First";
  else
    cout << "Second";
  cout << endl;
  return 0;
}
#endif
