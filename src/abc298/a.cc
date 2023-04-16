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
  bool maru = false;

  rep(i, n) {
    if (s[i] == 'x') {
      cout << "No\n";
      return 0;
    } else if (s[i] == 'o') {
      maru = true;
    }
  }
  if (maru)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
#endif
