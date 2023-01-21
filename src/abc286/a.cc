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
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  vector<int> bv(av);
  rep(i, q - p + 1) {
    bv[p - 1 + i] = av[r - 1 + i];
    bv[r - 1 + i] = av[p - 1 + i];
  }
  rep(i, n) {
    cout << bv[i];
    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
