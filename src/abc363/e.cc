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

  ll h, w, y;
  cin >> h >> w >> y;
  vector<vector<ll>> am(h, vector<ll>(w));
  rep(i, h) {
    rep(j, w) { cin >> am[i][j]; }
  }
  priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>,
                 greater<pair<ll, pair<int, int>>>>
      que;
  vector<vector<bool>> pushed(h, vector<bool>(w, false));
  rep(i, w) {
    que.push({am[0][i], {0, i}});
    que.push({am[h - 1][i], {h - 1, i}});
    pushed[0][i] = pushed[h - 1][i] = true;
  }
  for (int i = 1; i < h - 1; i++) {
    que.push({am[i][0], {i, 0}});
    que.push({am[i][w - 1], {i, w - 1}});
    pushed[i][0] = pushed[i][w - 1] = true;
  }
  ll n_drop = 0;
  vector<vector<bool>> drop(h, vector<bool>(w, false));

  for (int i = 1; i <= y; i++) {
    while (que.size()) {
      auto node = que.top();
      if (i < node.first)
        break;
      que.pop();
      auto [r, c] = node.second;
      if (!drop[r][c])
        n_drop++;
      drop[r][c] = true;

      vector<pair<int, int>> neighbors = {
          {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}};
      for (auto [n_r, n_c] : neighbors) {
        if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w && !pushed[n_r][n_c]) {

          que.push({am[n_r][n_c], {n_r, n_c}});
          pushed[n_r][n_c] = true;
        }
      }
    }
    cout << h * w - n_drop << endl;
  }
  return 0;
}
