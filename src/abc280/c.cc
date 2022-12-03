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
  string s, t;
  cin >> s >> t;
  rep(i, s.size()) {
    if (s[i] != t[i]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << s.size() + 1 << endl;
  return 0;
}
#endif
