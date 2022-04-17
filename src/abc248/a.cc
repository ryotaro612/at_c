#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  vector<bool> a(10, false);

  for (auto c : s) {
    a[c - '0'] = true;
  }
  rep(i, a.size()) {
    if (!a[i]) {
      cout << i << endl;
    }
  }

  return 0;
}
#endif
