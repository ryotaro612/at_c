#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> naka(n, vector<bool>(n, true));
  vector<vector<int>> am(m, vector<int>(n));
  rep(i, m) {
    rep(j, n) {
      cin >> am[i][j];
      am[i][j]--;
      if (j) {
        naka[am[i][j]][am[i][j - 1]] = naka[am[i][j - 1]][am[i][j]] = false;
      }
    }
  }
  int res = 0;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      if (naka[i][j])
        res++;
    }
  }
  cout << res << endl;
  return 0;
}
#endif
