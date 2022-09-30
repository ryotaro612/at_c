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
  int x, y, z;
  cin >> x >> y >> z;
  if (x * y < 0) {
    cout << abs(x) << endl;
    return 0;
  }
  // x とyが同じ側
  if (x * z > 0) {
    vector<int> t = {abs(x), abs(y), abs(z)};
    sort(t.begin(), t.end());
    if (t[0] == abs(y)) {
      cout << -1 << endl;
      return 0;
    } else {
      cout << abs(x) << endl;
    }
  } else {
    if (abs(x) < abs(y)) {
      cout << abs(x) << endl;
      return 0;
    } else {
      cout << abs(z) * 2 + abs(x) << endl;
    }
  }

  return 0;
}
#endif
