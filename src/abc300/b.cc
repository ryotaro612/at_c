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

bool is_same_am(vector<vector<char>> &am, vector<vector<char>> &bm) {
  int h = am.size(), w = am[0].size();
  rep(i, h) {
    rep(j, w) {
      if (am[i][j] != bm[i][j]) {
        return false;
      }
    }
  }
  return true;
}

vector<vector<char>> rotate(vector<vector<char>> am, int s, int t) {
  int h = am.size(), w = am[0].size();
  vector<vector<char>> res(h, vector<char>(w));
  //  cout << s << "--> " << t << endl;
  rep(i, h) {
    int x = i - s;
    if (x < 0)
      x += h;

    rep(j, w) {
      int y = j - t;
      if (y < 0)
        y += w;
      res[x][y] = am[i][j];
    }
  }
  // rep(i, h) {
  //   rep(j, w) cout << res[i][j];
  //   cout << endl;
  // }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> am(h, vector<char>(w)), bm(h, vector<char>(w));
  rep(i, h) {
    rep(j, w) { cin >> am[i][j]; }
  }
  rep(i, h) {
    rep(j, w) { cin >> bm[i][j]; }
  }
  rep(i, h) {
    rep(j, w) {
      auto em = rotate(am, i, j);
      if (is_same_am(em, bm)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
#endif
