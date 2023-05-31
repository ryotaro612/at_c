#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> av(n + 1);
  rep(i, n + 1) cin >> av[i];
  int k = 1 << 30;
  rep(i, n) k = min(k, abs(av[i] - av[i + 1]));

  vector<vector<int>> bm(k, vector<int>(n + 1, 0));
  vector<int> base(n + 1);
  rep(i, n + 1) { base[i] = av[i] / k; }
  rep(i, k) {
    rep(j, n + 1) {
      bm[i][j] = base[j];
      av[j] -= base[j];
      assert(av[j] >= 0);
    }
  }
  rep(i, k) {
    rep(j, n + 1) {
      if (av[j]) {
        bm[i][j]++;
        av[j]--;
      }
    }
  }
  cout << k << endl;
  rep(i, k) {
    rep(j, n + 1) { cout << bm[i][j] << " \n"[j == n]; }
  }
}
#endif
