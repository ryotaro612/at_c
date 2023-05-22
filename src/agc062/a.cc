#ifndef ONLINE_JUDGE
define _GLIBCXX_DEBUG
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
  int t;
  cin >> t;
  rep(_, t) {
    int n;
    string s;
    cin >> n >> s;
    if (s.back() == 'A') {
      cout << "A\n";
      continue;
    }
    bool done = false;
    rep(j, n - 1) {
      if (s[j] == 'B' && s[j + 1] == 'A') {
        cout << "A\n";
        done = true;
        break;
      }
    }
    if (!done) {
      cout << "B\n";
    }
  }
  return 0;
}
#endif
