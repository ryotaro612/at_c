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
// #ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sm(h);
  vector<vector<bool>> grid(h, vector<bool>(w, false));
  rep(i, h) cin >> sm[i];
  queue<tuple<int, int>> que;
  if (sm[0][0] != 's') {
    cout << "No\n";
    return 0;
  }
  grid[0][0] = true;
  map<char, char> mp;
  mp['s'] = 'n';
  mp['n'] = 'u';
  mp['u'] = 'k';
  mp['k'] = 'e';
  mp['e'] = 's';
  que.push({0, 0});
  while (que.size()) {
    auto [r, c] = que.front();
    que.pop();
    vector<pair<int, int>> neighbors = {
        {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}};
    for (auto [n_r, n_c] : neighbors) {
      if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w && !grid[n_r][n_c] &&
          sm[n_r][n_c] == mp[sm[r][c]]) {
        grid[n_r][n_c] = true;
        que.push({n_r, n_c});
      }
    }
  }
  if (grid[h - 1][w - 1]) {
    cout << "Yes\n";
    return 0;
  }

  cout << "No\n";
  return 0;
}
// #endif
