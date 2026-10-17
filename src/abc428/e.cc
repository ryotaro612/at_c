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

tuple<ll, ll> rec(int node, vector<vector<int>> &g,
                  map<int, set<tuple<ll, ll, ll>>> &dist, int parent) {

  for (auto &child : g[node]) {
    if (child == parent)
      continue;

    auto [sub_di, sub_des] = rec(child, g, dist, node);
    dist[node].insert({sub_di + 1ll, sub_des, child});

    if (dist[node].size() > 2) {
      dist[node].erase(dist[node].begin());
    }
  }
  if (dist[node].size() == 0) {
    return {0ll, node};
  }
  auto [di, des, child] = (*dist[node].rbegin());
  return {di, des};
}

void rec2(int node, vector<vector<int>> &g,
          map<int, set<tuple<ll, ll, ll>>> &dist, vector<ll> &res, ll d,
          ll descendant) {

  res[node] = descendant;

  if (dist[node].size() > 0) {
    auto [di, des, _] = (*dist[node].rbegin());
    if (d < di) {
      res[node] = des;
    } else if (d == di) {
      res[node] = max(res[node], des);
    }
  }
  for (auto &child : g[node]) {
    if (res[child] != -1) {
      continue;
    }
    ll cand_d = d + 1ll;
    ll cand_descendant = descendant;
    if (dist[node].size() == 1) {
      rec2(child, g, dist, res, cand_d, cand_descendant);
      continue;
    }
    set<tuple<ll, ll>> temp;
    temp.insert({cand_d, cand_descendant});
    auto [a, b, c] = *dist[node].rbegin();
    if (c == child) {
      auto [x, y, z] = *dist[node].begin();
      temp.insert({x + 1ll, y});
    } else {
      temp.insert({a + 1ll, b});
    }
    auto [new_d, new_descendant] = *temp.rbegin();
    rec2(child, g, dist, res, new_d, new_descendant);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  map<int, set<tuple<ll, ll, ll>>> dist;

  rec(0, g, dist, -1);

  vector<ll> res(n, -1);
  auto [__, descendant, _] = *dist[0].rbegin();
  res[0] = descendant;

  for (auto &child : g[0]) {
    auto [di, des, ch] = *dist[0].rbegin();
    if (child == ch) {
      if (dist[0].size() > 1) {
        auto [a, b, c] = *dist[0].begin();
        rec2(child, g, dist, res, a + 1ll, b);
      } else {
        rec2(child, g, dist, res, 1ll, 0ll);
      }
    } else {
      rec2(child, g, dist, res, di + 1ll, descendant);
    }
  }

  rep(i, n) { cout << res[i] + 1 << endl; }

  return 0;
}
