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
  ll n;
  cin >> s >> n;
  int s_n = s.size();
  ll temp = 0;
  for (int i = 0; i < s_n; i++) {
    if (s[i] == '1')
      temp += (1ll << (s_n - 1 - i));
  }
  if (temp > n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < s_n; i++) {
    if (s[i] == '?') {
      if (temp + (1ll << (s_n - 1 - i)) <= n) {
        temp += (1ll << (s_n - 1 - i));
      }
    }
  }
  cout << temp << endl;
  return 0;
}
#endif
