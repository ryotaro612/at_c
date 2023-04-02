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
  string s;

  rep(i, 8) {
    cin >> s;
    rep(j, 8) {
      if (s[j] == '*') {
        cout << (char)('a' + j) << 8 - i << endl;
      }
    }
  }
  return 0;
}
#endif
