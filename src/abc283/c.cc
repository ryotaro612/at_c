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
  int n = s.size();
  int i = 0;
  while (i < n) {
    if (i == n - 1) {
      res++;
      i++;
    } else {
      if (s[i] == '0' && s[i + 1] == '0') {
        res++;
        i += 2;
      } else {
        res++;
        i++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
#endif
