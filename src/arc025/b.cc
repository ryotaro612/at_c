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

void acc(vector<vector<int>> &grid) {
  int h = grid.size();
  int w = grid[0].size();
  rep(i, h) {
    rep(j, w) {
      if (i)
        grid[i][j] += grid[i - 1][j];
      if (j)
        grid[i][j] += grid[i][j - 1];
      if (i && j)
        grid[i][j] -= grid[i - 1][j - 1];
    }
  }
}
int compute_area(vector<vector<int>> &grid, int r1, int c1, int r2, int c2) {

  int area = grid[r2][c2];
  if (r1 && c1) {
    area += grid[r1 - 1][c1 - 1];
  }
  if (r1)
    area -= grid[r1 - 1][c2];
  if (c1)
    area -= grid[r2][c1 - 1];
  return area;
}

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> black(h, vector<int>(w, 0)), white(h, vector<int>(w, 0));
  rep(i, h) {
    rep(j, w) {
      if (i % 2) {
        if (j % 2)
          cin >> black[i][j];
        else
          cin >> white[i][j];
      } else {
        if (j % 2)
          cin >> white[i][j];
        else
          cin >> black[i][j];
      }
    }
  }
  acc(black);
  acc(white);
  // rep(i, h) {
  //   rep(j, w) { cout << white[i][j] << " "; }
  //   cout << endl;
  // }
  int result = 0;
  rep(i, h) {
    rep(j, w) {
      rep(a, i + 1) {
        rep(b, j + 1) {
          if (compute_area(black, a, b, i, j) ==
              compute_area(white, a, b, i, j)) {
            // cout << a << " " << b << " " << i << " " << j << endl;
            result = max(result, (i - a + 1) * (j - b + 1));
          }
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}
#endif
