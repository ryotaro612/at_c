#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(x)                                                                 \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #x << " = " << x   \
       << "\e[39m" << endl;
#else
#define dbg(x)
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
ll const mod = 1000000007ll;

ll solve(int i, int carry, vector<int> &av, vector<vector<ll>> &dp) {
  // dbg(i);
  // dbg(carry);
  if ((int)av.size() == i)
    return 1ll;
  
  if (dp[i][carry] != -1)
    return dp[i][carry];
  
  ll res = 0ll;
  rep(j, 10) {
    if (j > av[i] + carry)
      break;
    int next_carry = (av[i] + carry - j) / 10;
    res += solve(i + 1, next_carry, av, dp);
    res %= mod;
  }
  return dp[i][carry] = res;
}
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  rep(i, 10) av.push_back(0);
  vector<vector<ll>> dp(n+10, vector<ll>(5001, -1));
  ll res = solve(0, 0, av, dp) - 1ll;
  if (res < 0)
    res += mod;
  cout << res << endl;
  return 0;
}
