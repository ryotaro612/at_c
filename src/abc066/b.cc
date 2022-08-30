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
  for (int i = 2; s.size() - i > 0; i += 2) {
    string a(s.begin(), s.end() - i);
    // cout << a << endl;
    bool ok = true;
    for (int i = 0; i < (int)a.size() / 2; i++) {
      if (a[i] != a[i + (int)a.size() / 2])
        ok = false;
    }
    if (ok) {
      cout << a.size() << endl;
      return 0;
    }
  }
  return 0;
}
#endif
