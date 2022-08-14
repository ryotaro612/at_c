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
  int l, r;
  cin >> l >> r;

  string s = "atcoder";
  for (int i = l - 1; i < r; i++)
    cout << s[i];
  cout << endl;

  return 0;
}

#endif
