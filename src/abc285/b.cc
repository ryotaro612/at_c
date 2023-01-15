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
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    int k = 0;
    for (; k + i < n; k++) {
      if (s[k] == s[k + i])
        break;
    }
    cout << max(k, 0) << endl;
  }

  return 0;
}
#endif
