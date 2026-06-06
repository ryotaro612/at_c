#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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
/*
  ソートする
  mapをつくる
 となりがなければ、残す
 a b c d e f
 a     d   f
   b   d   f
 a   c   e
 となりがある。
 */
int main() {
  ll n, d;
  cin >> n >> d;
  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    mp[a]++;
  }
  if (d == 0) {
    ll res = 0;
    for (auto [v, freq] : mp) {
      res += freq - 1ll;
    }
    cout << res << endl;
    return 0;
  }

  ll res = 0;
  for (auto [v, freq] : mp) {
    dbg(v, freq);
    ll i = 0;
    vector<ll> tmp;
    while (mp[v + (d * i)]) {
      tmp.push_back(mp[v + (d * i)]);
      mp[v + (d * i)] = 0;
      i++;
    }
    if (tmp.size() == 0)
      continue;
    vector<vector<ll>> dp(tmp.size(), vector<ll>(2, 1000000000000ll));
    dp[0][0] = 0;
    dp[0][1] = tmp[0];
    for (int j = 1; j < (int)tmp.size(); j++) {
      dp[j][0] = dp[j - 1][1];
      dp[j][1] = tmp[j] + min(dp[j - 1][0], dp[j - 1][1]);
    }
    res += min(dp.back()[0], dp.back()[1]);
  }

  cout << res << endl;

  return 0;
}
