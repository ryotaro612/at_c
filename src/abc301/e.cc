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

int bit_count(int v) {
  int res = 0;
  while (v) {
    if (v & 1)
      res++;
    v >>= 1;
  }
  return res;
}

ll measure(vector<string> &am, pair<int, int> start, pair<int, int> goal,
           map<pair<pair<int, int>, pair<int, int>>, ll> &cache) {
  pair<pair<int, int>, pair<int, int>> key = {start, goal};
  if (cache.find(key) != cache.end()) {
    return cache[key];
  }
  int h = am.size();
  int w = am[0].size();
  vector<ll> d(h * w, 1000000000000ll);
  d[start.first * w + start.second] = 0;
  queue<pair<int, int>> que;
  que.push(start);
  while (que.size()) {
    auto [r, c] = que.front();
    que.pop();
    vector<pair<int, int>> neighbors = {
        {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}};
    for (auto [n_r, n_c] : neighbors) {
      if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w && am[n_r][n_c] != '#' &&
          d[n_r * w + n_c] > 1ll + d[r * w + c]) {
        d[n_r * w + n_c] = 1ll + d[r * w + c];
        que.push({n_r, n_c});
      }
    }
  }
  return cache[{start, goal}] = cache[{goal, start}] =
             d[goal.first * w + goal.second];
}
int main() {
  int h, w;
  ll t;
  cin >> h >> w >> t;
  vector<string> am(h);
  pair<int, int> start, goal;
  vector<pair<int, int>> snacks;

  rep(i, h) {
    cin >> am[i];
    rep(j, w) {
      if (am[i][j] == 'S')
        start = {i, j};
      else if (am[i][j] == 'o')
        snacks.push_back({i, j});
      else if (am[i][j] == 'G')
        goal = {i, j};
    }
  }
  map<pair<pair<int, int>, pair<int, int>>, ll> cache;
  if (measure(am, start, goal, cache) > t) {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<ll>> dist_cache(snacks.size() + 1,
                                vector<ll>(snacks.size() + 1, 100000000000ll));
  rep(i, snacks.size() + 1) {
    rep(j, snacks.size()) {
      dist_cache[i][j] =
          measure(am, i == 0 ? start : snacks[i - 1], snacks[j], cache);
    }
    dist_cache[i][snacks.size()] =
        measure(am, i == 0 ? start : snacks[i - 1], goal, cache);
  }
  vector<vector<ll>> dp(snacks.size() + 1,
                        vector<ll>(1 << snacks.size(), 10000000000ll));
  priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>,
                 greater<pair<ll, pair<int, int>>>>
      que;
  dp[0][0] = 0;
  que.push({0, {0, 0}});

  int res = 0;
  while (que.size()) {
    auto item = que.top();
    que.pop();
    ll cost = item.first;
    auto [node_i, mask] = item.second;
    if (dp[node_i][mask] < cost)
      continue;

    // dbg(node_i, mask, dp[node_i][mask]);
    ll to_goal = dist_cache[node_i][snacks.size()];
    //        measure(am, node_i == 0 ? start : snacks[node_i - 1], goal, cache);
    // dbg(node_i == 0 ? start : snacks[node_i - 1], to_goal);
    if (dp[node_i][mask] + to_goal > t)
      continue;

    res = max(res, bit_count(mask));
    if(res == (int)snacks.size())
      break;

    rep(i, snacks.size()) {

      // ll to_snack = measure(am, node_i == 0 ? start : snacks[node_i - 1],
      //                       snacks[i], cache);
      ll to_snack = dist_cache[node_i][i];
      int new_mask = mask | (1 << i);
      if (dp[node_i][mask] + to_snack < dp[i + 1][new_mask]) {
        dp[i + 1][new_mask] = dp[node_i][mask] + to_snack;
        que.push({dp[i + 1][new_mask], {i + 1, new_mask}});
      }
    }
  }
  cout << res << endl;
  return 0;
}
