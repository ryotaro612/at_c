#include <bits/stdc++.h>
#include <string>
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

void traverse(int prev_r, int prev_c, int zero_r, int zero_c, int times,
              int n_diff, vector<vector<int>> &cm, int &res) {
  if (n_diff == 0) {
    res = min(res, times);
    return;
  }
  int h = cm.size();
  int w = cm[0].size();

  if (abs(h - 1 - zero_r) + abs(w - 1 - zero_c) > 24 - times)
    return;
  if (n_diff + times > 24)
    return;
  vector<pair<int, int>> neighbors = {{zero_r - 1, zero_c},
                                      {zero_r, zero_c + 1},
                                      {zero_r + 1, zero_c},
                                      {zero_r, zero_c - 1}};
  for (auto [n_r, n_c] : neighbors) {
    if (n_r == prev_r && n_c == prev_c)
      continue;

    if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w) {
      int diff = n_diff;
      if (n_r * w + (n_c + 1) == cm[n_r][n_c])
        diff++;
      cm[zero_r][zero_c] = cm[n_r][n_c];
      cm[n_r][n_c] = 0;
      if (zero_r * w + (zero_c + 1) == cm[zero_r][zero_c])
        diff--;
      traverse(zero_r, zero_c, n_r, n_c, times + 1, diff, cm, res);
      cm[n_r][n_c] = cm[zero_r][zero_c];
      cm[zero_r][zero_c] = 0;
    }
  }
}

int main() {
  int h, w, n_diff = 0, zero_r = -1, zero_c = -1;
  cin >> h >> w;
  vector<vector<int>> cm(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) {
      cin >> cm[i][j];
      if (cm[i][j]) {
        if (cm[i][j] != i * w + (j + 1))
          n_diff++;
      } else {
        zero_r = i;
        zero_c = j;
      }
    }
  }
  int res = 24;
  traverse(-1, -1, zero_r, zero_c, 0, n_diff, cm, res);
  cout << res << endl;
  return 0;
}
