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
  ll a, b;
  cin >> a >> b;
  ll res = 1;
  rep(i, b) { res *= a; }
  cout << res << endl;

  return 0;
}
#endif
