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
  int n, k;
  cin >> n >> k;
  set<ll> as;
  rep(i, n) {
    ll a;
    cin >> a;
    as.insert(a);
  }
  set<ll> less;
  for (auto e : as) {
    less.insert(e);
    if (as_int(less.size()) == k)
      break;
  }
  int res = 0;
  while (true) {
    if (less.find(res) == less.end()) {
      cout << res << endl;
      return 0;
    }
    res++;
  }

  return 0;
}
#endif
