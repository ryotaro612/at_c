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
  vector<vector<int>> av(n);
  rep(i, n) {
    vector<int> a(i + 1);
    av[i] = a;
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        av[i][j] = 1;
        // cout << i << " doge " << endl;
      }

      else {
        av[i][j] = av[i - 1][j - 1] + av[i - 1][j];
      }
    }
    // cout << " i " << i << endl;
    // for (auto e : a) {
    //   cout << e << " ";
    // }
    // cout << endl;
  }
  rep(i, av.size()) {
    rep(j, av[i].size()) {
      cout << av[i][j];
      if (j < (int)av[i].size() - 1)
        cout << " ";
      else
        cout << endl;
    }
  }
  return 0;
}
#endif
