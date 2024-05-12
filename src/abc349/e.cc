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

int calc_score(vector<vector<ll>> &am, vector<vector<int>> &grid) {
  int player = 0;
  rep(i, 3) {
    if (grid[i][0] && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
      player = grid[i][0];
    }
    if (grid[0][i] && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
      player = grid[0][i];
    }
  }
  if (grid[0][0] && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    player = grid[0][0];
  if (grid[0][2] && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    player = grid[0][2];
  if (player) {
    return player;
  }
  rep(i, 3) {
    rep(j, 3) {
      if (grid[i][j] == 0)
        return 0;
    }
  }
  ll score[] = {0, 0};
  rep(i, 3) {
    rep(j, 3) { score[grid[i][j] - 1] += am[i][j]; }
  }
  if (score[0] > score[1])
    return 1;
  else
    return 2;
}

int proceed(int player, vector<vector<ll>> &am, vector<vector<int>> &grid) {
  auto winner = calc_score(am, grid);
  if (winner)
    return winner;

  rep(i, 3) {
    rep(j, 3) {
      if (grid[i][j] == 0) {
        grid[i][j] = player;
        int res;
        if (player == 1)
          res = proceed(2, am, grid);
        else
          res = proceed(1, am, grid);

        grid[i][j] = 0;
        if (res == player)
          return player;
      }
    }
  }
  if (player == 1)
    return 2;
  return 1;
}
int main() {
  vector<vector<ll>> am(3, vector<ll>(3));
  rep(i, 3) {
    rep(j, 3) { cin >> am[i][j]; }
  }
  vector<vector<int>> grid(3, vector<int>(3, 0));
  if (proceed(1, am, grid) == 1)
    cout << "Takahashi\n";
  else
    cout << "Aoki\n";
  return 0;
}
