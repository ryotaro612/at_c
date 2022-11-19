#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int freq[301];
int orig_freq[301];
int am[301][301];
#ifdef ONLINE_JUDGE
int main() {
  int n_row, n_col, n, h, w;
  cin >> n_row >> n_col >> n >> h >> w;
  int total = 0;
  rep(r, n_row) {
    rep(c, n_col) {
      cin >> am[r][c];
      if (orig_freq[am[r][c]] == 0) {
        total++;
      }
      orig_freq[am[r][c]]++;
    }
  }
  // cout << total << endl;

  for (int k = 0; k <= n_row - h; k++) {
    int current = total;
    rep(j, 301) { freq[j] = orig_freq[j]; }
    for (int i = k; i < k + h; i++) {
      for (int j = 0; j < w; j++) {
        if (freq[am[i][j]] == 1)
          current--;
        freq[am[i][j]]--;
      }
    }
    for (int l = 0; l <= n_col - w; l++) {
      cout << current;
      if (l < n_col - w)
        cout << " ";
      else
        cout << endl;
      for (int i = k; i < k + h; i++) {
        if (freq[am[i][l]] == 0)
          current++;
        freq[am[i][l]]++;
      }
      if (l < n_col - w) {
        for (int i = k; i < k + h; i++) {
          if (freq[am[i][l + w]] == 1)
            current--;
          freq[am[i][l + w]]--;
        }
      }
    }
    // for (int i = k; i < k + h; i++) {
    //   for (int j = n_col - w; j < n_col; j++) {
    //     freq[am[i][j]]++;
    //   }
    // }
  }

  return 0;
}
#endif
