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
  int n, m;
  cin >> n >> m;
  vector<int> av(m, 0);
  rep(i, m) {
    int c, a;
    cin >> c;
    rep(j, c) {
      cin >> a;
      av[i] |= 1 << (a - 1);
    }
  }
  int res = 0;
  rep(i, 1 << m) {
    int mask = 0;
    rep(j, m) {
      if (i & (1 << j)) {
        mask |= av[j];
      }
    }
    if (mask == (1 << n) - 1)
      res++;
  }
  cout << res << endl;
  return 0;
}
#endif
