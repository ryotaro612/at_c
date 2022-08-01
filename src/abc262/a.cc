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
  int y;
  cin >> y;
  while (true) {
    if (y % 4 == 2) {
      cout << y;
      return 0;
    }
    y++;
  }
  return 0;
}
#endif
