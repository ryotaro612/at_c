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
  int n, m, x, t, d;
  cin >> n >> m >> x >> t >> d;
  if (x <= m) {
    cout << t << endl;
    return 0;
  } // m < x
  cout << t - (x - m) * d << endl;
  return 0;
}
#endif
