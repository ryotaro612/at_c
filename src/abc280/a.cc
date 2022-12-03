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
  int h, w;
  cin >> h >> w;
  int result = 0;
  rep(i, h) {
    rep(i, w) {
      char a;
      cin >> a;
      if (a == '#')
        result++;
    }
  }
  cout << result << endl;
  return 0;
}
#endif
