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
  vector<vector<ll>> alphas(26);
  string s;
  cin >> s;
  rep(i, s.size()) { alphas[s[i] - 'A'].push_back(i); }
  ll res = 0;
  for (ll i = 0; i < 26; i++) {
    if (alphas[i].size() < 2)
      continue;
    ll base = 0;
    for (int j = 1; j < (int)alphas[i].size(); j++) {
      base += alphas[i][j] - alphas[i][0] - 1ll;
    }
    res += base;
    dbg(base);
    for (int j = 1; j < (int)alphas[i].size() - 1; j++) {
      base -= (alphas[i][j] - alphas[i][j - 1]) * (alphas[i].size() -1 - j);
	  base -= (alphas[i][j] - alphas[i][j - 1] - 1ll);
      dbg(base);
      res += base;
    }
  }

  cout << res << endl;

  return 0;
}
