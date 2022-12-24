#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<set<char>> stk;
  set<char> box;
  rep(i, n) {
    char c = s[i];
    if ('a' <= c && c <= 'z') {
      if (box.find(c) == box.end()) {
        box.insert(c);
        if (stk.size() > 0) {
          stk.back().insert(c);
        }
      } else {
        cout << "No" << endl;
        return 0;
      }
    } else if (c == '(') {
      stk.push_back(set<char>());
    } else { // c == ')'
      for (char c : stk.back()) {
        box.erase(c);
      }
      stk.pop_back();
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
