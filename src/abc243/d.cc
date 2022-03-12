#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(int n, ll x, string &s) {
  stack<char> stk;

  for (char c : s) {
    if (c == 'U') {
      if (stk.empty()) {
        x /= 2ll;
      } else {
        stk.pop();
      }
    } else if (c == 'L') {
      stk.push('L');
    } else { // c== 'R'
      stk.push('R');
    }
  }

  string a;
  while (!stk.empty()) {
    a.push_back(stk.top());
    stk.pop();
  }
  reverse(a.begin(), a.end());
  s = a;
  rep(i, s.size()) {
    if (s[i] == 'U') {
      x /= 2ll;
    } else if (s[i] == 'L') {
      x *= 2ll;
    } else { // s[i] == 'R'
      x *= 2ll;
      x += 1ll;
    }
  }
  return x;
}
#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll x;
  cin >> n >> x;
  string s;
  cin >> s;
  cout << solve(n, x, s) << endl;
  return 0;
}
#endif
