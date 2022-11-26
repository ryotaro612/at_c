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
  int res = 0;
  for (auto c : s) {
    if (c == 'w')
      res += 2;
    else
      res += 1;
  }
  cout << res << endl;
  return 0;
}
#endif
