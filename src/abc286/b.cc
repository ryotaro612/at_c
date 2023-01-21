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
  stack<char> stk;
  for (auto c : s) {
    if (c == 'a') {
      if (stk.size() && stk.top() == 'n')
        stk.push('y');
    }
    stk.push(c);
  }

  string res;
  while (!stk.empty()) {
    res.push_back(stk.top());
    stk.pop();
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
}
#endif
