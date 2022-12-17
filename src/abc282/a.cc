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
  int k;
  cin >> k;
  string s;
  rep(i, k) {
    char c = 'A' + i;
    s.push_back(c);
  }
  cout << s << endl;
  return 0;
}
#endif
