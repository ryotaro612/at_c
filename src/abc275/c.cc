#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  vector<string> sv(9);
  rep(i, 9) cin >> sv[i];

  vector<pair<int, int>> points;
  rep(i, 9) {
    rep(j, 9) {
      if (sv[i][j] == '#')
        points.push_back({i, j});
    }
  }
  if (points.size() < 4) {
    cout << 0 << endl;
    return 0;
  }
  int n = points.size();
  if (points.size() < 2) {
    cout << 0 << endl;
    return 0;
  }
  int result = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      auto [i_x, i_y] = points[i];
      auto [j_x, j_y] = points[j];
      // cout << "(" << i_x << "," << i_y << ") (" << j_x << "," << j_y << ") ->
      // ";
      int d_x = j_x - i_x;
      int d_y = j_y - i_y;

      int k_x = i_x - d_y;
      int k_y = i_y + d_x;
      // cout << "(" << k_x << "," << k_y << ")" << endl;
      if (0 <= k_x && k_x < 9 && 0 <= k_y && k_y < 9 && sv[k_x][k_y] == '#') {
        int d_x = i_x - j_x;
        int d_y = i_y - j_y;
        int l_x = j_x + d_y;
        int l_y = j_y - d_x;
        if (0 <= l_x && l_x < 9 && 0 <= l_y && l_y < 9 && sv[l_x][l_y] == '#') {
          result++;
        }
      }
    }
  }
  cout << result / 2 << endl;
  return 0;
}
#endif
