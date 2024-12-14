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
  int h, w;
  ll x;
  int p, q;
  cin >> h >> w >> x >> p >> q;
  p--;
  q--;
  vector<vector<ll>> grid(h, vector<ll>(w));
  vector<vector<bool>> visit(h, vector<bool>(w, false));
  visit[p][q] = true;

  rep(i, h) {
    rep(j, w) { cin >> grid[i][j]; }
  }
  ll takahashi = grid[p][q];
  vector<pair<int, int>> neigh = {
      {p - 1, q}, {p, q + 1}, {p + 1, q}, {p, q - 1}};
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>,
                 greater<tuple<ll, ll, ll>>>
      que;
  for (auto [a, b] : neigh) {
    if (0 <= a && a < h && 0 <= b && b < w) {
      que.push({grid[a][b], a, b});
      dbg("foo", grid[a][b], a, b);
      visit[a][b] = true;
    }
  }
  dbg("doge");
  while (que.size()) {
    auto [v, a, b] = que.top();
    dbg(v, a, b);
    if (takahashi < v || takahashi <= v * x) {
      break;
    }
    takahashi += v;
    que.pop();

    vector<pair<int, int>> neighbors = {
        {a - 1, b}, {a, b + 1}, {a + 1, b}, {a, b - 1}};
    for (auto [r, c] : neighbors) {
      if (0 <= r && r < h && 0 <= c && c < w && !visit[r][c]) {
        visit[r][c] = true;
        que.push({grid[r][c], r, c});
      }
    }
  }
  cout << takahashi << endl;
  return 0;
}
