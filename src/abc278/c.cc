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
  ll n, q;
  cin >> n >> q;
  map<ll, set<ll>> ff;
  rep(i, q) {
    ll t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      ff[a].insert(b);
    } else if (t == 2) {
      if (ff[a].find(b) != ff[a].end()) {
        ff[a].erase(b);
      }
    } else {
      if (ff[a].find(b) != ff[a].end() && ff[b].find(a) != ff[b].end()) {
        cout << "Yes";
      } else
        cout << "No";
      cout << endl;
    }
  }
  return 0;
}
#endif
