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
  string t;
  int n, inf = 1 << 29;
  cin >> t >> n;

  vector<int> prev(t.size() + 1, inf);
  prev[0] = 0;
  rep(_, n) {
    int a;
    cin >> a;
    vector<int> dp = prev;
    rep(j, a) {
      string s;
      cin >> s;
      rep(k, t.size()) {
        if (k + s.size() > t.size())
          continue;
        bool ok = true;
        rep(l, s.size()) {
          if (s[l] != t[k + l])
            ok = false;
        }
        if (ok)
          dp[k + s.size()] = min(dp[k + s.size()], 1 + prev[k]);
      }
    }
    prev = dp;
  }
  if (prev[t.size()] < inf)
    cout << prev[t.size()] << endl;
  else
    cout << -1 << endl;
  return 0;
}
