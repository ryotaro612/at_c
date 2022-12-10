#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <string>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

bool is_upper(char c) { return c >= 'A' && c <= 'Z'; }

bool is_six(string s, int start) {
  int d = 0;
  for (int i = start; i < start + 6; i++) {
    d *= 10;
    if ('0' <= s[i] && s[i] <= '9')
      d += s[i] - '0';
    else
      return false;
  }
  return 100000 <= d && d <= 999999;
}

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  int n = s.size();
  // if (n == 1) {
  //   if (is_upper(s[0]))
  //     cout << "Yes" << endl;
  //   else
  //     cout << "No" << endl;
  //   return 0;
  // }
  // if (n == 6) {
  //   if (is_six(s, 0))
  //     cout << "Yes" << endl;
  //   else
  //     cout << "No" << endl;
  //   return 0;
  // }
  if (n == 8 && is_upper(s[0]) && is_six(s, 1) && is_upper(s[n - 1])) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
#endif
