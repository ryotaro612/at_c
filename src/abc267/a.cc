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
  map<string, int> mp;
  mp["Monday"] = 5;
  mp["Tuesday"] = 4;
  mp["Wednesday"] = 3;
  mp["Thursday"] = 2;
  mp["Friday"] = 1;
  cout << mp[s] << endl;
  return 0;
}
#endif
