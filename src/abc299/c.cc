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
  int n;
  string s;
  cin >> n >> s;
  int res = -1;
  for (int left = 0, right = 0; left < n;) {
    right = max(left, right);
    if (s[left] == '-') {
      left++;
      continue;
    }

    while (right < n && s[right] == 'o')
      right++;
    if (left)
      res = max(res, right - left);
    if (right < n)
      res = max(res, right - left);
    left = right;
  }
  cout << res << endl;
  return 0;
}
#endif
