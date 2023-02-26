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
  cin >> s;
  rep(i, s.size()) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      cout << i + 1 << endl;
      ;
    }
  }
  return 0;
}
#endif
