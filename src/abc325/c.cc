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

int find_root(int node, vector<int> &par) {
  if (par[node] < 0)
    return node;
  return par[node] = find_root(par[node], par);
}
int is_same_group(int node, int node2, vector<int> &par) {
  return find_root(node, par) == find_root(node2, par);
}

void unite(int node, int node2, vector<int> &par) {
  if (is_same_group(node, node2, par))
    return;
  int root1 = find_root(node, par);
  int root2 = find_root(node2, par);
  if (par[root1] < par[root2]) {
    par[root1] += par[root2];
    par[root2] = root1;

  } else {
    par[root2] += par[root1];
    par[root1] = root2;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  vector<int> par(h * w, -1);
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == '.')
        continue;
      vector<pair<int, int>> deltas = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};
      for (auto [d_r, d_c] : deltas) {
        int n_r = r + d_r, n_c = c + d_c;
        if (0 <= n_r && n_r < h && 0 <= n_c && n_c < w &&
            grid[n_r][n_c] == '#') {
          unite(r * w + c, n_r * w + n_c, par);
        }
      }
    }
  }
  set<int> res;
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == '#')
        res.insert(find_root(r*w+c, par));
    }
  }
  dbg(res);
  cout << res.size() << endl;
  return 0;
}
