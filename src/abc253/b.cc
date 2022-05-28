#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sv(h);
  rep(i, h) cin >> sv[i];
  pair<int, int> pos, pos2;
  int c = 0;
  rep(i, h) {
    rep(j, w) {
      if (sv[i][j] == 'o') {
        if (c == 0) {
          // cout << "doge" << endl;
          pos.first = i;
          pos.second = j;
          c++;
        } else {
          pos2.first = i;
          pos2.second = j;
        }
      }
    }
  }
  cout << abs(pos.first - pos2.first) + abs(pos.second - pos2.second) << endl;
  return 0;
}
#endif
