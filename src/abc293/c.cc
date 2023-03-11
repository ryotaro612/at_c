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

void rec(int r, int c, vector<vector<int>> &m, set<int> &d, int &res) {
  int h = m.size();
  int w = m[0].size();
  if (d.find(m[r][c]) != d.end())
    return;
  if (r == h - 1 && c == w - 1) {
    res++;
    return;
  }
  d.insert(m[r][c]);
  if (r <= h - 2) {
    rec(r + 1, c, m, d, res);
  }
  if (c <= w - 2) {
    rec(r, c + 1, m, d, res);
  }
  d.erase(m[r][c]);
}

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> m(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) { cin >> m[i][j]; }
  }
  int res = 0;
  set<int> d;
  rec(0, 0, m, d, res);
  cout << res << endl;
  return 0;
}
#endif
