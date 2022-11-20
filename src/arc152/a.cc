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
  int n, l;
  cin >> n >> l;
  if (l <= 2) {
    cout << "Yes" << endl;
    return 0;
  }

  vector<int> av(n);
  rep(i, n) cin >> av[i];
  bool flip = false;
  int cur = 1;

  rep(i, n) {
    if (flip) {
      if (av[i] == 2) {
        cout << "No" << endl;
        return 0;
      }

    } else {
      if (av[i] == 1) {
        if (cur + 2 < l)
          cur += 2;
        else
          flip = true;
      } else { // av[i] == 2
        if (cur + 3 < l)
          cur += 3;
        else
          flip = true;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
