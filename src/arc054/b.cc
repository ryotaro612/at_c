#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

ld func(ld x, ld p) { return x + p / (ld)pow(2.0, (x / 1.5)); }

#ifdef ONLINE_JUDGE
int main() {
  ld p, lb = 0, ub = 100000000ll;
  cin >> p;

  while (abs(func(ub, p) - func(lb, p)) > 0.0000000001) {
    ld left_mid = (2.0 * lb + ub) / 3.0;
    ld right_mid = (lb + 2.0 * ub) / 3.0;
    // cout << fixed << setprecision(12) << func(left_mid, p) << " "
    //      << func(right_mid, p) << " " << left_mid << " " << right_mid <<
    //      endl;
    if (func(left_mid, p) < func(right_mid, p))
      ub = right_mid;
    else
      lb = left_mid;
  }
  // cout << lb << " | "
  //      << "p " << p << " " << p / (ld)pow(2.0, (lb / 1.5)) << endl;
  cout << fixed << setprecision(12) << func(lb, p) << endl;
  return 0;
}
#endif
