#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ld calc(ld x1, ld y1, ld x2, ld y2, ld x, ld y) {
  return (y - y1) * (x2 - x1) - (y2 - y1) * (x - x1);
}

#ifdef ONLINE_JUDGE
int main() {
  ld ax, ay, bx, by, cx, cy, dx, dy;
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
  if (calc(bx, by, dx, dy, ax, ay) * calc(bx, by, dx, dy, cx, cy) >= 0) {
    cout << "No" << endl;
    return 0;
  }
  if (calc(ax, ay, cx, cy, dx, dy) * calc(ax, ay, cx, cy, bx, by) >= 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
