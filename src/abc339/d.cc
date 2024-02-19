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
const ll inf = 10000000000000ll;

int move(int pos, int top, int right, vector<string> &grid) {
  int n = grid.size();
  int r = pos / n + top;
  int c = pos % n + right;
  if (0 <= r && r < n && 0 <= c && c < n && grid[r][c] != '#')
    return r * n + c;
  return pos;
}

ll solve(int a, int b, vector<vector<ll>> &dp, vector<string> &grid) {
  if (dp[a][b] >= 0)
    return dp[b][a] = dp[a][b];
  if (a == b)
    return dp[a][b] = 0;

  dp[a][b] = -2;
  ll res = inf;
  vector<pair<int, int>> di = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  for (auto [top, right] : di) {
    int next_a = move(a, top, right, grid);
    int next_b = move(b, top, right, grid);
    if (dp[next_a][next_b] != -2) {
      res = min(res, 1ll + solve(next_a, next_b, dp, grid));
    }
  }
  return dp[a][b] = res;
}
int main() {
  int n;
  cin >> n;
  vector<string> grid(n);
  int a = -1, b = -1;
  rep(i, n) {
    cin >> grid[i];
    rep(j, n) {
      if (grid[i][j] == 'P') {
        if (a == -1)
          a = i * n + j;
        else
          b = i * n + j;
      }
    }
  }
  queue<pair<int, int>> que;
  vector<vector<ll>> dp(n * n, vector<ll>(n * n, inf));
  dp[a][b] = 0;
  que.push({a, b});
  ll res = inf;
  while (que.size()) {
    auto [a, b] = que.front();
    que.pop();
    vector<pair<int, int>> di = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto [top, right] : di) {
      int next_a = move(a, top, right, grid);
      int next_b = move(b, top, right, grid);
      if (dp[a][b] + 1ll < dp[next_a][next_b]) {
        dp[next_a][next_b]= dp[a][b] + 1ll;
        que.push({next_a, next_b});
        if (next_a == next_b) {
          res = min(res, dp[next_a][next_b]);
        }
      }
    }
  }
  if (res == inf)
    cout << -1 << endl;
  else
    cout << res << endl;
  return 0;
}
