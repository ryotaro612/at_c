#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  map<ll, bool> mp;
  ll res = 0ll;
  rep(i, n) {
    ll a;
    cin >> a;
    if (mp[a]) {
      mp[a] = false;
      res++;
    } else
      mp[a] = true;
  }
  cout << res << endl;
  return 0;
}
#endif
