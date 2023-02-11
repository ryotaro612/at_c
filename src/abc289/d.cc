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
  int n, m, x;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  cin >> m;
  set<int> bs;
  rep(i, m) {
    int b;
    cin >> b;
    bs.insert(b);
  }
  cin >> x;
  vector<int> dp(x + 1, false);
  dp[0] = true;
  rep(i, x + 1) {
    if (dp[i]) {
      for (auto a : av) {
        if (a + i <= x && bs.find(a + i) == bs.end()) {
          dp[a + i] = true;
        }
      }
    }
  }
  cout << (dp[x] ? "Yes" : "No") << endl;
  return 0;
}
#endif
