#include <bits/stdc++.h>
#include <limits>
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
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  vector<int> cnt(n, 0);
  function<int(int)> rec = [&](int node) {
    if (g[node].size() == 1) {
      return cnt[node] = 1;
    }
    cnt[node] = 1;
    for (auto child : g[node]) {
      if (cnt[child] > 0)
        continue;
      cnt[node] += rec(child);
    }
    return cnt[node];
  };
  rec(0);
  int res = 1;
  int mx = 0;
  for(auto e: g[0]) {
    res += cnt[e];
    mx = max(mx, cnt[e]);
  }
  cout << res - mx << endl;
  return 0;
}
