#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string line, inv_line;
  char color = '.';
  rep(i, n) {
    line += string(b, color);
    if (color == '.')
      color = '#';
    else
      color = '.';
  }
  color = '#';

  rep(i, n) {
    inv_line += string(b, color);
    if (color == '.')
      color = '#';
    else
      color = '.';
  }
  string x = line;
  rep(i, n) {
    rep(j, a) { cout << x << endl; }
    if (x == line)
      x = inv_line;
    else
      x = line;
  }
  return 0;
}
#endif
