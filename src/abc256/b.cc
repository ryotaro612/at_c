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
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  int res = 0;
  vector<int> masu(4, 0);

  rep(i, n) {
    vector<int> next_masu(4, 0);
    masu[0] += 1;
    int a = av[i];
    rep(j, 4) {
      if (3 < j + a) {
        res += masu[j];
      } else {
        next_masu[j + a] = masu[j];
      }
    }
    masu = next_masu;
  }
  cout << res << endl;
  return 0;
}
#endif
