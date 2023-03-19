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

ll solve(vector<ll> patterns, int k) {
  for (int i = 62; i >= 0; i--) {
    vector<ll> temp;
    ll mask = (ll)(1ll << (ll)i);
    for (auto pattern : patterns) {

      if (pattern & mask) {
        temp.push_back(pattern);
      }
    }
    if (as_int(temp.size()) >= k) {
      patterns = temp;
    }
  }
  ll res = (ll)(1ll << 62ll) - 1ll;
  for (auto pattern : patterns)
    res &= pattern;
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n), prefix(n + 1, 0);
  rep(i, n) {
    cin >> av[i];
    prefix[i + 1] += av[i] + prefix[i];
  }
  vector<ll> patterns;
  rep(i, n) {
    for (int j = i; j < n; j++) {
      patterns.push_back(prefix[j + 1] - prefix[i]);
    }
  }
  cout << solve(patterns, k) << endl;
  return 0;
}
#endif
