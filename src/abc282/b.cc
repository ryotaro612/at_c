#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
string sv[31];
#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  rep(i, n) cin >> sv[i];
  int res = 0;
  rep(i, n - 1) {
    for (int j = i + 1; j < n; j++) {
      bool ok = true;
      rep(k, m) {
        if (sv[i][k] == 'x' && sv[j][k] == 'x') {
          ok = false;
        }
      }
      if (ok)
        res++;
    }
  }
  cout << res << endl;

  return 0;
}
#endif
