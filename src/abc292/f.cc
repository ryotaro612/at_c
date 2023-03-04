#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

/**
 *  度数をラジアンに変換
 * e.g, 60 degree to 1/2
 */
ld dtor(ld degree) { return degree * M_PI / 180.0; }

/**
 * 2次元ベクトルをdegree度回転させる
 */
pair<ld, ld> rotate_vector(ld x, ld y, ld degree) {
  ld theta = dtor(degree);
  return {cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y};
}

#ifdef ONLINE_JUDGE
int main() {

  ld a, b;
  cin >> a >> b;
  if (b < a)
    swap(b, a);
  ld lb = 0, ub = 90;
  while (ub - lb > 0.0000000001) {
    ld mid = (ub + lb) / 2.0;
    // https://cplusplus.com/reference/cmath/tan/
    ld x = a, y = a * tan(dtor(mid));
    if (b < y) {
      ub = mid;
      continue;
    }
    pair<ld, ld> delta = rotate_vector(x, y, 120);
    ld x2 = x + delta.first;
    ld y2 = y + delta.second;
    if (0 <= x2 && x2 <= a && 0 <= y2 && y2 <= b)
      lb = mid;
    else
      ub = mid;
  }
  // cout << ub << endl;
  cout << fixed << setprecision(12) << a / cos(dtor(ub)) << endl;

  return 0;
}
#endif
