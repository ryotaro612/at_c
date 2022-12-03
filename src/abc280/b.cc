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
  int n;
  cin >> n;
  vector<ll> sv(n);
  rep(i, n) cin >> sv[i];
  rep(i, n) {
    ll s = sv[i];
    if (i == 0) {
      cout << s;
    } else {
      cout << s - sv[i - 1];
    }
    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
