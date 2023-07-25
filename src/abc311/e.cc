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
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> av(n), bv(n);
  vector<vector<int>> grid(h, vector<int>(w, 0));
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    grid[--a][--b]++;
  }

  rep(r, h) {
    rep(c, w) {
      if (r)
        grid[r][c] += grid[r - 1][c];
      if (c)
        grid[r][c] += grid[r][c - 1];
      if (r && c)
        grid[r][c] -= grid[r - 1][c - 1];
    }
  }
  ll res = 0;

  rep(r, h) {
    rep(c, w) {
      int lb = -1, ub = h + 1;
      while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        int br = r + mid - 1, bc = c + mid - 1;
        if (br >= h || bc >= w) {
          ub = mid;
          continue;
        }
        if (br < r || bc < c) {
          lb = mid;
          continue;
        }

        int count = grid[br][bc];
        if (r)
          count -= grid[r - 1][bc];
        if (c)
          count -= grid[br][c - 1];
        if (r && c)
          count += grid[r - 1][c - 1];

        if (count)
          ub = mid;
        else
          lb = mid;
      }
      res += lb;
    }
  }
  cout << res << endl;
  return 0;
}
