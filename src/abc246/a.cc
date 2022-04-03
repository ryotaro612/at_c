
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  vector<int> xv(3), yv(3);
  rep(i, 3) { cin >> xv[i] >> yv[i]; }
  unordered_map<int, int> xc, yc;
  int x, y;
  rep(i, 3) {
    xc[xv[i]]++;
    yc[yv[i]]++;
  }
  for (auto kv : xc) {
    if (kv.second == 1)
      x = kv.first;
  }
  for (auto kv : yc) {
    if (kv.second == 1)
      y = kv.first;
  }
  cout << x << " " << y << endl;
  return 0;
}
#endif
