#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  rep(i, n) {
    if (s[i] == '1')
      s[i] = 'l';
    if (s[i] == '0')
      s[i] = 'o';
    if (t[i] == '1')
      t[i] = 'l';
    if (t[i] == '0')
      t[i] = 'o';
  }
  if (s == t)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
#endif
