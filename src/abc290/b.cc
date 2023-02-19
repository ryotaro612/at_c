#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iterator>
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
  int n, k;
  string s;
  cin >> n >> k >> s;
  map<int, bool> mp;
  rep(i, n) {
    if (s[i] == 'o') {
      mp[i] = true;
    }
  }
  string t(n, 'x');
  int i = 0;
  for (auto [j, v] : mp) {
    if (i < k)
      t[j] = 'o';
    i++;
    if (i == k)
      break;
  }
  cout << t << endl;

  return 0;
}
#endif
