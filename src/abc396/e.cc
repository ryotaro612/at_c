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

bool traverse(vector<set<int>> &ab, int i, int color,
              vector<vector<pair<int, bool>>> &g, vector<bool> &visited) {

  for (auto [j, flip] : g[i]) {
    if (flip) {
      if (ab[color].count(j)) {
        return false;
      }
      if (ab[color ^ 1].count(j)) {
        continue;
      }
      ab[color ^ 1].insert(j);
      visited[j] = true;
      if (!traverse(ab, j, color ^ 1, g, visited)) {
        return false;
      }
    } else {
      if (ab[color ^ 1].count(j)) {
        return false;
      }
      if (ab[color].count(j)) {
        continue;
      }

      ab[color].insert(j);
      visited[j] = true;
      if (!traverse(ab, j, color, g, visited)) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vector<ll> xv(m), yv(m), zv(m), res(n);
  rep(i, m) {
    cin >> xv[i] >> yv[i] >> zv[i];
    xv[i]--;
    yv[i]--;
  }

  for (ll bit = 0; bit < 31; bit++) {
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < m; i++) {
      bool flip = zv[i] & (1ll << bit);
      g[xv[i]].push_back({yv[i], flip});
      g[yv[i]].push_back({xv[i], flip});
    }
    vector<bool> visited(n, false);
    rep(i, n) {
      if (visited[i])
        continue;
      vector<set<int>> ab(2);
      ab[0].insert(i);
      if (!traverse(ab, i, 0, g, visited)) {
        cout << -1 << endl;
        return 0;
      }

      set<int> *target = ab[0].size() < ab[1].size() ? &ab[0] : &ab[1];
      for (auto e : *target) {
        res[e] |= (1ll << bit);
      }
    }
  }
  rep(i, n) { cout << res[i] << " \n"[i == n - 1]; }

  return 0;
}
Pp
