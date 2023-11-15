
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
vector<ll> compute_divisors(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i)
        res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
const ll MOD = 998244353ll;
int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<ll> dp(n + 1, 0);
  for (int i = 1; i < n; i++) {
    if (n % i)
      continue;

    vector<bool> pattern(i, true);
    rep(j, n) {
      if (s[j] == '.') {
        pattern[j % i] = false;
      }
    }
    dp[i] = 1ll;
    for (auto e : pattern) {
      if (e) {
        dp[i] *= 2ll;
        dp[i] %= MOD;
      }
    }
    for (int j = 1; j < i; j++) {
      if (i % j == 0) {
        dp[i] -= dp[j];
        dp[i] = (dp[i] + MOD) % MOD;
      }
    }
  }
  ll res = 0;
  for (auto e : dp) {
    res += e;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
