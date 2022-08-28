#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ld pow(ld a, int x) {
  ld res = 1;
  for (int i = 0; i < x; i++) {
    res *= a;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ld> dp(101, 0);
  dp[1] = 3.5;
  for (int i = 2; i <= n; i++) {
    ld f = floor(dp[i - 1]);
    dp[i] += f / (ld)6 * dp[i - 1];
    for (int j = f + 1; j <= 6; j++) {
      dp[i] += j * (ld)1 / (ld)6;
    }
  }
  cout << fixed << setprecision(12) << dp[n] << endl;
  return 0;
}
#endif
