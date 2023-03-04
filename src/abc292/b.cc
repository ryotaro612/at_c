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
  int n, q;
  cin >> n >> q;
  map<int, int> mp;
  rep(i, q) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      mp[x]++;
    } else if (c == 2) {
      mp[x] += 2;
    } else {
      if (mp[x] >= 2)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
#endif
