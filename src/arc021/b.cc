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
  int l;
  cin >> l;
  vector<int> bv(l), av(l, 0);
  rep(i, l) cin >> bv[i];

  rep(i, 31) {
    // cout << "i " << i << endl;
    for (int a0 : {0, 1}) {
      vector<int> bit(l, 0);
      bit[0] = a0;
      // cout << "a0 " << bit[0] << endl;
      rep(j, l - 1) {
        if (bit[j]) {
          if (bv[j] & (1 << i)) {
            // nop
          } else {
            bit[j + 1] = 1;
          }
        } else {
          if (bv[j] & (1 << i)) {
            bit[j + 1] = 1;
          } else {
            // nop
          }
        }
        // cout << "a" << j + 1 << " " << bit[j + 1] << endl;
      }
      if (((bit[l - 1] ^ bit[0]) << i) == (bv[l - 1] & (1 << i))) {
        rep(j, l) { av[j] |= (bit[j] << i); }
        break;
      } else if (a0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (auto a : av) {
    cout << a << endl;
  }
  return 0;
}
#endif
