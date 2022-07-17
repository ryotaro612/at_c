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
  string s;
  cin >> s;
  map<char, int> mp;
  for (char c : s) {
    mp[c] += 1;
  }
  for (auto [a, c] : mp) {
    if (c == 1) {
      cout << a << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
#endif
