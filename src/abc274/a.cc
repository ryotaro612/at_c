#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  double a, b;
  cin >> a >> b;
  double c = b / a;
  c *= 10000;
  double d = round(c);
  d /= 10000;
  printf("%.3f", d);
  cout << endl;

  return 0;
}
//#endif
