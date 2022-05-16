#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int solve(int n, string &s) {
  multiset<int> fragments;
  rep(i, n) {
    if (s[i] == 'R') {
      int count = 0;
      for (int j = 1;
           0 <= i - j && i + j < n && s[i - j] == 'A' && s[i + j] == 'C'; j++) {
        count = j;
      }
      if (count > 0)
        fragments.insert(count);
    }
  }
  int res = 0;
  bool odd = true;
  while (!fragments.empty()) {
    if (odd) {
      auto iter = prev(fragments.end(), 1);
      fragments.erase(iter);
      if (*iter > 1) {
        fragments.insert(*iter - 1);
      }
    } else {
      auto iter = fragments.begin();
      fragments.erase(iter);
    }
    odd = !odd;
    res++;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << solve(n, s) << endl;
  return 0;
}
#endif
