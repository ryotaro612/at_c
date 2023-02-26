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
  set<pair<int, int>> pass;
  pass.insert({0, 0});
  int x = 0, y = 0;
  for (auto c : s) {
    if (c == 'R') {
      x++;
    } else if (c == 'L') {
      x--;
    } else if (c == 'U')
      y++;
    else
      y--;
    // cout << x << " " << y << endl;
    if (pass.find({x, y}) != pass.end()) {
      cout << "Yes" << endl;
      return 0;
    }
    pass.insert({x, y});
  }
  cout << "No" << endl;

  return 0;
}
#endif
