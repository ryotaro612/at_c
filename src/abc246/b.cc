#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ld a, b;
  cin >> a >> b;
  ld len = sqrt(a * a + b * b);
  // cout << len << endl;
  ld div = 1.0 / len;
  ld x = a * div;
  ld y = b * div;
  cout << fixed << setprecision(12) << x;
  cout << " ";
  cout << fixed << setprecision(12) << y << endl;
  return 0;
}
#endif
