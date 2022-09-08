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
  int x, y;
  cin >> x >> y;
  set<int> a = {1, 3, 5, 7, 8, 10, 12};
  set<int> b = {4, 6, 9, 11};
  set<int> c = {2};
  vector<set<int>> ss = {a, b, c};
  for (set<int> s : ss) {
    if (s.find(x) != s.end() && s.find(y) != s.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
#endif
