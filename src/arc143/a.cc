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
  ll a, b, c;
  cin >> a >> b >> c;
  vector<ll> x = {a, b, c};
  sort(x.begin(), x.end());
  if (x[0] + x[1] < x[2]) {
    cout << -1 << endl;
    return 0;
  }
  cout << x[2] << endl;

  return 0;
}
#endif
