#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <ostream>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)
/**
4
aace
ceaa

 */
#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  vector<int> freq_s(26, 0), freq_t(26, 0);
  rep(i, n) {
    freq_s[s[i] - 'a']++;
    freq_t[t[i] - 'a']++;
  }
  rep(i, 26) {
    if (freq_s[i] != freq_t[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int ub = n + 1, lb = -1;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    int i = n - mid;
    for (auto c : t) {
      if (i < n && s[i] == c)
        i++;
    }
    // cout << mid << " " << ok << endl;
    if (i == n) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  cout << n - lb << endl;
  return 0;
}
#endif
