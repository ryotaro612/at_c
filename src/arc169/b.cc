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
int main() {
  int n;
  ll s;
  cin >> n >> s;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<ll> dp(n, 0);
  dp[0] = 1;
  ll sum = av[0];
  int pos = 0;
  dbg("doge");
  for (int i = 1; i < n; i++) {
    sum += av[i];
    while (sum > s) {
      sum -= av[pos];
      pos++;
    }
    dp[i] = i - pos + 1;
    if (pos)
      dp[i] += dp[pos-1] + pos;
  }
  dbg(dp);
  ll res = 0;
  rep(i, n)
    res += dp[i];
  cout << res << endl;
  return 0;
}
