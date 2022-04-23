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
  int n, k;
  cin >> n >> k;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];

  vector<vector<int>> counter(n, vector<int>(26, 0));
  rep(i, n) {
    for (auto c : sv[i]) {
      counter[i][c - 'a']++;
    }
  }
  int res = 0;
  for (int i = 0; i < (1 << n); i++) {
    vector<int> current(26, 0);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        rep(k, 26) { current[k] += counter[j][k]; }
      }
    }
    int temp = 0;
    rep(j, 26) {
      if (current[j] == k)
        temp++;
    }
    res = max(temp, res);
  }
  cout << res << endl;
  return 0;
}
#endif
