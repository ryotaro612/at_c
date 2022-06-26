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
  int n, x;
  cin >> n >> x;
  vector<char> s;
  rep(i, 26) {
    char a = 'A' + i;
    rep(j, n) { s.push_back(a); }
  }
  cout << s[x - 1] << endl;
  return 0;
}
#endif
