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
  string s;
  cin >> s;
  vector<ll> patterns(1 << 10, 0);
  patterns[0]++;
  ll res = 0ll;
  int current = 0;
  rep(i, s.size()) {
    int d = s[i] - '0';
    if (current & (1 << d))
      current -= (1 << d);
    else
      current += (1 << d);
    res += patterns[current];
    patterns[current]++;
    // for (int i = 9; i >= 0; i--) {
    //   bool a = (current & (1 << i));
    //   cout << a;
    // }
    // cout << endl;
  }
  cout << res << endl;
  return 0;
}
#endif
