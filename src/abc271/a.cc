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
  int n;
  cin >> n;
  map<int, char> mp;
  rep(i, 10) mp[i] = i + '0';
  for (int i = 10; i < 16; i++) {
    mp[i] = 'A' + i - 10;
  }
  cout << mp[n >> 4];
  cout << mp[n & 0xF] << endl;
  cout << endl;
  return 0;
}
#endif
