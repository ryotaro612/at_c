#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

pair<int, int> solve(int n, string t) {
  int x = 0, y = 0;
  int dx = 1, dy = 0;

  for (char c : t) {
    if (c == 'S') {
      x += dx;
      y += dy;
    } else {
      if (dx == 1 && dy == 0) {
        dx = 0;
        dy = -1;
      } else if (dx == 0 && dy == -1) {
        dx = -1;
        dy = 0;
      } else if (dx == -1 && dy == 0) {
        dx = 0;
        dy = 1;
      } else if (dx == 0 && dy == 1) {
        dx = 1;
        dy = 0;
      }
    }
  }
  return {x, y};
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  pair<int, int> res = solve(n, t);
  cout << res.first << " " << res.second << endl;
  return 0;
}
#endif
