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
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'a') {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
#endif
