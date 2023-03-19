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
  int h, w;
  cin >> h >> w;
  rep(i, h) {
    rep(j, w) {
      int a;
      cin >> a;
      char c;
      if (a == 0)
        c = '.';
      else
        c = 'A' + a - 1;
      cout << c;
      if (w - 1 == j)
        cout << endl;
    }
  }
  return 0;
}
#endif
