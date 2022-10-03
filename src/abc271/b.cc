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
  int n, q;
  cin >> n >> q;
  vector<vector<ll>> am(n);
  rep(i, n) {
    int l;
    cin >> l;
    am[i] = vector<ll>(l);
    rep(j, l) { cin >> am[i][j]; }
  }
  rep(i, q) {
    int s, t;
    cin >> s >> t;
    cout << am[s - 1][t - 1] << endl;
  }

  return 0;
}
#endif
