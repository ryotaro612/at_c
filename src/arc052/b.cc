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

ld calc_area(ld x, ld r, ld h, ld a, ld b) {
  if (b <= x)
    return 0;
  if (x + h <= a)
    return 0;
  ld height = h - max((ld)0, min(a - x, h));
  ld radius = r * height / h;
  ld res = height * radius * radius * M_PI / 3.0;

  height = h - max((ld)0, min(b - x, h));
  radius = r * height / h;
  res -= height * radius * radius * M_PI / 3.0;
  return res;
}

ld solve(vector<ld> &xv, vector<ld> &rv, vector<ld> &hv, ld a, ld b) {
  ld res = 0;
  rep(i, xv.size()) res += calc_area(xv[i], rv[i], hv[i], a, b);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, q;
  cin >> n >> q;
  vector<ld> xv(n), rv(n), hv(n);
  rep(i, n) cin >> xv[i] >> rv[i] >> hv[i];
  rep(i, q) {
    ld a, b;
    cin >> a >> b;
    cout << fixed << setprecision(12) << solve(xv, rv, hv, a, b) << endl;
  }
  return 0;
}
#endif
