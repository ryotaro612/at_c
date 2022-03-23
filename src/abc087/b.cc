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
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int res = 0;
  rep(i, a + 1) {
    rep(j, b + 1) {
      rep(k, c + 1) {
        if (i * 500 + j * 100 + k * 50 == x)
          res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
