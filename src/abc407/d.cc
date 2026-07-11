#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
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

vector<bool> done(1 << 20, false);

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<ll>> grid(h, vector<ll>(w));
  ll base = 0;
  deque<pair<ll, ll>> que;
  rep(i, h) rep(j, w) {
    cin >> grid[i][j];
    base ^= grid[i][j];
  }
  ll res = max(0ll, base);

  rep(i, h * w) {

    int r = i / w;
    int c = i % w;
    res = max(res, base ^ grid[r][c]);
    done[1ll << i] = true;
    que.push_back({1ll << i, grid[r][c]});
  }

  while (!que.empty()) {
    auto [mask, val] = que.front();
    que.pop_front();
    rep(i, h * w) {
      if ((mask & (1ll << i)) == 0)
        continue;

      int r = i / w;
      int c = i % w;

      vector<pair<int, int>> neighbors = {
          {r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}};
      for (auto [nr, nc] : neighbors) {
        if (nr < 0 || nr >= h || nc < 0 || nc >= w)
          continue;
        ll ni = nr * w + nc;
        if (done[mask | (1ll << ni)])
          continue;

        done[mask | (1ll << ni)] = true;
        ll new_val = val ^ grid[nr][nc];
        res = max(res, base ^ new_val);
        que.push_back({mask | (1ll << ni), new_val});
      }
    }
  }

  cout << res << endl;

  return 0;
}
