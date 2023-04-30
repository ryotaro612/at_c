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

ll solve(int i, ll g_a, ll g_b, ll aa[], ll ba[],
         map<tuple<int, ll, ll>, ll> &dp, int n) {
  if (i == n)
    return lcm(g_a, g_b);
  if (dp.count({i, g_a, g_b}))
    return dp[{i, g_a, g_b}];

  return dp[{i, g_a, g_b}] =
             max(solve(i + 1, gcd(g_a, aa[i]), gcd(g_b, ba[i]), aa, ba, dp, n),
                 solve(i + 1, gcd(g_a, ba[i]), gcd(g_b, aa[i]), aa, ba, dp, n));
}

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  ll aa[51], ba[51];
  rep(i, n) cin >> aa[i] >> ba[i];
  map<tuple<int, ll, ll>, ll> dp;
  cout << solve(0, 0, 0, aa, ba, dp, n) << endl;
  return 0;
}
// #endif
