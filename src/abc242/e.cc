#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <ll prime> class Mod final {
public:
  Mod(ll v) : v(v){};

private:
  ll v;
};

using Mod998244353 = Mod<998244353ll>;
const ll MOD = 998244353ll;

ll solve_item(int n, string &s) {

  vector<vector<ll>> dp((n + 1) / 2 + 1, vector<ll>(2, 0ll));
  // 0ならまだおなじ
  // 1なら小さい
  dp[0][0] = 1ll;
  int dp_size = static_cast<int>(dp.size());
  rep(i, dp_size - 1) {
    char c = s[i];
    dp[i + 1][0] = dp[i][0];
    dp[i + 1][1] = dp[i][0] * (ll)(c - 'A') % MOD;
    dp[i + 1][1] += dp[i][1] * 26ll % MOD;
    dp[i + 1][1] %= MOD;
  }

  // rep(i, dp.size()) {
  //   cout << i << " -> " << dp[i][0] << " , " << dp[i][1] << endl;
  // }
  for (int i = n / 2 - 1; 0 <= i; i--) {
    if (s[i] < s[n - 1 - i]) {
      return (dp.back()[0] + dp.back()[1]) % MOD;
    } else if (s[n - 1 - i] < s[i]) {
      return dp.back()[0];
    }
  }
  return (dp.back()[0] + dp.back()[1]) % MOD;
}

vector<ll> solve(int t, vector<int> &nv, vector<string> &sv) {
  vector<ll> res(t);
  rep(i, t) res[i] = solve_item(nv[i], sv[i]);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  vector<int> nv(t);
  vector<string> sv(t);
  rep(i, t) { cin >> nv[i] >> sv[i]; }
  vector<ll> res = solve(t, nv, sv);
  for (auto &e : res)
    cout << e << endl;
  return 0;
}
#endif
