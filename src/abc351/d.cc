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

class UnionFind {
public:
  vector<int> par;
  /**
   *  グループの総数
   */
  UnionFind(int n) { par = vector<int>(n, -1); }

  int find_root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = find_root(par[a]);
  }

  int is_same_group(int a, int b) { return find_root(a) == find_root(b); }

  void unite(int a, int b) {
    if (is_same_group(a, b))
      return;
    int root_a = find_root(a), root_b = find_root(b);
    if (group_size(root_a) > group_size(b)) {
      par[root_a] += par[root_b];
      par[root_b] = root_a;
    } else {
      par[root_b] += par[root_a];
      par[root_a] = root_b;
    }
  }
  int group_size(int a) { return -par[find_root(a)]; }
  /**
   * グループの総数を返す。
   */
  int count_groups() {
    unordered_set<int> groups;
    rep(i, par.size()) { groups.insert(find_root(i)); }
    return groups.size();
  }
};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> sm(h);
  rep(i, h) cin >> sm[i];
  bool exist = false;
  rep(r, h) {
    rep(c, w) {
      if (sm[r][c] == '#')
        exist = true;
    }
  }
  if (!exist) {
    cout << h * w << endl;
    return 0;
  }

  vector<vector<int>> grid(h, vector<int>(w, -1));
  rep(r, h) {
    rep(c, w) {
      if (sm[r][c] == '#') {
        grid[r][c] = 0;
        continue;
      }
      bool magnet = false;
      for (auto [adj_r, adj_c] : vector<pair<int, int>>{
               {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}}) {
        if (0 <= adj_r && adj_r < h && 0 <= adj_c && adj_c < w &&
            sm[adj_r][adj_c] == '#') {
          magnet = true;
        }
      }
      if (magnet)
        grid[r][c] = 1;
      else
        grid[r][c] = 2;
    }
  }
  UnionFind uf(h * w);
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == 2) {
        for (auto [adj_r, adj_c] : vector<pair<int, int>>{
                 {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}}) {
          if (0 <= adj_r && adj_r < h && 0 <= adj_c && adj_c < w &&
              grid[adj_r][adj_c] == 2) {
            uf.unite(r * w + c, adj_r * w + adj_c);
          }
        }
      }
    }
  }
  map<int, set<pair<int, int>>> add;
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == 1) {
        for (auto [adj_r, adj_c] : vector<pair<int, int>>{
                 {r - 1, c}, {r, c + 1}, {r + 1, c}, {r, c - 1}}) {
          if (0 <= adj_r && adj_r < h && 0 <= adj_c && adj_c < w &&
              grid[adj_r][adj_c] == 2) {
            add[uf.find_root(adj_r * w + adj_c)].insert({r, c});
          }
        }
      }
    }
  }
  int res = 1;
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == 2) {
        res = max(res, (int)uf.group_size(r * w + c) +
                           (int)add[uf.find_root(r * w + c)].size());
      }
    }
  }
  cout << res << endl;

  return 0;
}
