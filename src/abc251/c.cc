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
  vector<string> sv(n);
  vector<ll> tv(n);
  rep(i, n) { cin >> sv[i] >> tv[i]; }
  unordered_map<string, ll> stov;
  rep(i, n) {
    if (stov.find(sv[i]) == stov.end()) {
      stov[sv[i]] = tv[i];
    }
  }
  ll max_score = -1ll;
  for (auto e : stov) {
    max_score = max(max_score, e.second);
  }
  unordered_set<string> candidates;
  for (auto e : stov) {
    if (max_score == e.second) {
      candidates.insert(e.first);
    }
  }
  rep(i, n) {
    if (tv[i] == max_score && candidates.find(sv[i]) != candidates.end()) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  return 0;
}
#endif
