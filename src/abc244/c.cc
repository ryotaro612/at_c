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
  int n;
  cin >> n;
  vector<int> available(2 * n + 2, true);
  available[0] = false;
  while (true) {
    rep(i, available.size()) {
      if (available[i]) {
        cout << i << endl;
        available[i] = false;
        break;
      }
    }
    int aoki;
    cin >> aoki;
    if (aoki == 0)
      return 0;
    else {
      available[aoki] = false;
    }
  }

  return 0;
}
#endif
