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
  set<char> cs(s.begin(), s.end());
  if (cs.size() == 26) {
    cout << "None" << endl;
  } else {
    rep(i, 26) {
      char c = 'a' + i;
      if (cs.find(c) == cs.end()) {
        cout << c << endl;
        break;
      }
    }
  }
  return 0;
}
#endif
