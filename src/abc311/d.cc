#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif
// g++ -fdiagnostics-color=always -g -O0 --std=c++17 -Wall
// -fsanitize=undefined,address
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> sm(n);
  rep(i, n) cin >> sm[i];
  vector<vector<bool>> visit(n, vector<bool>(m, false));
  queue<pair<int, int>> que;
  vector<vector<int>> d(n, vector<int>(m, 1 << 28));
  visit[1][1] = true;
  d[1][1] = 0;
  que.push({1, 1});
  while (size(que)) {
    auto [r, c] = que.front();
    que.pop();
    vector<pair<int, int>> delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto [d_r, d_c] : delta) {
      int c_r = r, c_c = c;
      while (sm[c_r + d_r][c_c + d_c] == '.') {
        c_r += d_r;
        c_c += d_c;
        visit[c_r][c_c] = true;
      }
      if (d[c_r][c_c] > d[r][c] + 1) {
        d[c_r][c_c] = d[r][c] + 1;
        que.push({c_r, c_c});
      }
    }
  }
  int res = 0;
  rep(i, n) debug(visit[i]);
  rep(i, n) {
    rep(j, m) {
      if (visit[i][j])
        res++;
    }
  }
  cout << res << endl;
  return 0;
}
