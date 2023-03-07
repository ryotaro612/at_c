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
  int x;
  cin >> x;
  map<int, int> mp;
  mp[4] = mp[5] = 8;
  mp[6] = mp[7] = 7;
  mp[8] = mp[9] = 6;
  mp[10] = mp[11] = 5;
  mp[12] = mp[13] = 4;
  mp[14] = mp[15] = 3;
  mp[16] = mp[17] = 2;
  mp[18] = mp[19] = 1;
  cout << mp[x / 100] << endl;
  return 0;
}
#endif
