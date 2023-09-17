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
  int n, m;
  cin >> n >> m;
  ll inf = (1ull << 63ull) - 1ull;
  vector<ll> xv(n, inf), yv(n, inf);
  vector<vector<tuple<int, ll, ll>>> dists(n);
  rep(_, m) {
    int a, b;
    ll x, y;
    cin >> a >> b >> x >> y;
    dists[--a].push_back({--b, x, y});
    dists[b].push_back({a, -x, -y});
  }
  queue<int> que;
  xv[0] = yv[0] = 0;
  que.push(0);
  while (que.size()) {
    int b = que.front();
    dbg("que", b);
    que.pop();
    for (auto [a, x, y] : dists[b]) {
      if (xv[a] == inf) {
        xv[a] = xv[b] + x;
        yv[a] = yv[b] + y;
        que.push(a);
      }
    }
  }
  dbg(xv);
  dbg(yv);
  rep(i, n) {
    if (xv[i] == inf) {
      cout << "undecidable";
    } else {
      cout << xv[i] << " " << yv[i];
    }
    cout << endl;
  }

  return 0;
}
