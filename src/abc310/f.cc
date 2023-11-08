#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}
pair<ll, ll> ext_gcd(ll a, ll b) {
  if (b == 0)
    return {1, 0};
  auto [x, y] = ext_gcd(b, a % b);
  return {y, x - a / b * y};
}
const ll MOD = 998244353ll;
ll mod_inv(ll a) {
  auto [x, _] = ext_gcd(a, MOD);
  return (x % MOD + MOD) % MOD;
}
ll mod_div(ll a, ll b) { return a * mod_inv(b) % MOD; }

int main() {

  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  vector<vector<ll>> dp(n + 1, vector<ll>(1 << 11, 0));
  dp[0][1] = 1;
  rep(i, n) {
    rep(j, 1 << 11) {

      ll prob = mod_inv(av[i]);
      for (int k = 1; k <= min(av[i], 10ll); k++) {
        int mask = 0;
        rep(l, 11) {
          if ((j & (1 << l)) && (k + l) <= 10) {
            mask |= (1 << (k + l));
          }
        }
        dp[i + 1][mask | j] += prob * dp[i][j] % MOD;
        dp[i + 1][mask | j] %= MOD;
      }
      dp[i + 1][j] += (av[i] - min(av[i], 10ll)) * prob % MOD * dp[i][j];
      dp[i+1][j] %=MOD;
    }
  }

  ll res = 0ll;
  rep(i, 1 << 11) {
    if (i & (1 << 10)) {
      res += dp[n][i];
      res %= MOD;
    }
  }
  dbg(dp[0]);
  cout << res << endl;
  return 0;
}

/*
    vector<vector<ll>> dp(n + 1, vector<ll>(11, 0));
  dp[0][0] = 1;
  rep(i, n) {
    ll prob = mod_inv(av[i]);
    rep(j, 11) dp[i + 1][j] = dp[i][j];
    rep(j, 11) {
      for (int k = 1; k <= av[i] && j + k <= 10; k++) {
        if (dp[i + 1][j + k] != 1) {
          dp[i + 1][j + k] += dp[i][j] * prob % MOD;
          dp[i + 1][j + k] %= MOD;
          if(i+1 == 2 && j + k == 2) {
            dbg("@", i, j , k, dp[i][j]);
          }

        }
      }
    }
  }
*/
