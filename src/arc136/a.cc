#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string solve(int n, string &s) {
  stack<char> stk;

  for (char c : s) {
    if (stk.empty())
      stk.push(c);
    else if (stk.top() == 'B') {
      if (c == 'A') {
        stk.pop();
        stk.push('A');
        stk.push('B');
      } else if (c == 'B') {
        stk.pop();
        stk.push('A');
      } else { // c == 'C'
        stk.push('C');
      }
    } else {
      stk.push(c);
    }
  }

  string res;
  while (!stk.empty()) {
    res.push_back(stk.top());
    stk.pop();
  }
  reverse(res.begin(), res.end());
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << solve(n, s) << endl;
  return 0;
}
#endif
