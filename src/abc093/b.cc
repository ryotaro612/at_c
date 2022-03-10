#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  set<ll> s;
  for (ll i = 0; i < k; i++) {
    if (a + i <= b)
      s.insert(a + i);
  }
  rep(i, k) {
    if (a <= b - i)
      s.insert(b - i);
  }
  for (auto e : s)
    cout << e << endl;
  return 0;
}
#endif
