#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  double a, b, d;
  cin >> a >> b >> d;
  const double pi = acos(-1);
  double theta = (pi * d) / (double)180;
  double x = cos(theta) * a - sin(theta) * b;
  double y = sin(theta) * a + cos(theta) * b;
  cout << fixed << setprecision(12) << x;
  cout << " ";
  cout << fixed << setprecision(12) << y << endl;

  return 0;
}
#endif
