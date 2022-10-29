#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

ll solve(ll n, map<ll, ll> &dp) {
  if (dp.find(n) == dp.end()) {
    if (n == 0) {
      return dp[n] = 1;
    } else {
      dp[n] = solve(n / 2ll, dp) + solve(n / 3ll, dp);
      return dp[n];
    }
  } else {
    return dp[n];
  }
}

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  map<ll, ll> dp;
  cout << solve(n, dp) << endl;
  return 0;
}
#endif
