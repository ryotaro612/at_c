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
  int x, y, n;
  cin >> x >> y >> n;
  int res = x * n;

  res = min(res, n / 3 * y + n % 3 * x);
  cout << res << endl;
  return 0;
}
#endif
