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
  int n;
  set<string> sv;
  cin >> n;
  set<char> cs = {'H', 'D', 'C', 'S'};
  set<char> cs2 = {'A', '2', '3', '4', '5', '6', '7',
                   '8', '9', 'T', 'J', 'Q', 'K'};
  rep(i, n) {
    string s;
    cin >> s;
    sv.insert(s);
    if (cs.find(s[0]) == cs.end() || cs2.find(s[1]) == cs2.end()) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (sv.size() == n) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
#endif
