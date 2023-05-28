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
  int n, m, h, k;
  string s;
  cin >> n >> m >> h >> k >> s;
  map<int, map<int, bool>> xy;

  rep(i, m) {
    int x, y;
    cin >> x >> y;
    xy[x][y] = true;
  }
  int x = 0, y = 0;
  for (auto c : s) {
    if (c == 'R') {
      x++;
    } else if (c == 'L')
      x--;
    else if (c == 'U')
      y++;
    else
      y--;
    h--;
    if (h < 0) {
      cout << "No\n";
      return 0;
    }
    if (h < k) {
      if (xy[x][y]) {
        h = k;
        xy[x][y] = false;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
#endif
