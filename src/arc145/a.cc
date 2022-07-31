#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
string solve(int n, string &s) {
  for (int i = 0; i < n; i++) {
    if (i == n - 1 - i)
      break;
    char left = s[i], right = s[n - 1 - i];
    if (left == 'A' && right == 'A') {
      continue;
    } else if (left == 'A' && right == 'B') {
      if (i == 0)
        return "No";
      else
        break;
    } else if (left == 'B' && right == 'A') {
      if (i == n - 1 - i - 1)
        return "No";
      else
        break;
    } else {
      break;
    }
  }
  return "Yes";
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
