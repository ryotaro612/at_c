#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  ll res = 0ll;
  while (a < b) {
    a *= k;
    res++;
  }
  cout << res << endl;
  return 0;
}
#endif
