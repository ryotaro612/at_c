#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<vector<int>> solve(int n) {
  vector<vector<int>> res(n, vector<int>(n));
  int count = 1;
  rep(i, n) {
    rep(j, n) { res[i][j] = count++; }
  }
  for (int i = 1; i < n - 1; i += 1) {
    for (int j = 1; j <= n - 2; j += 2) {
      swap(res[i][j], res[i][j + 1]);
    }
  }

  return res;
}
#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<int>> res = solve(n);

  rep(i, n) {
    rep(j, n) {
      cout << res[i][j];
      if (j == n - 1)
        cout << endl;
      else
        cout << " ";
    }
  }

  return 0;
}
#endif
/**
 1  2  3  4
 5  7  6  8
 9 11 10 12
13 14 15 16
 */
