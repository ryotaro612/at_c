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
  if (s.size() > t.size()) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
#endif
