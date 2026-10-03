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
#include <tuple>
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  vector<ll> xv(n), yv(n);
  rep(i, n) { cin >> xv[i] >> yv[i]; }
  UnionFind uf(n + q);
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>,
                 greater<tuple<ll, ll, ll>>>
      que;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      ll dist = abs(xv[i] - xv[j]) + abs(yv[i] - yv[j]);
      que.push({dist, i, j});
    }
  }

  rep(_, q) {
    int t;
    cin >> t;

    if (t == 1) {
      ll a, b;
      cin >> a >> b;
      dbg(t, a, b);
      rep(i, xv.size()) {
        que.push({abs(xv[i] - a) + abs(yv[i] - b), i, xv.size()});
      }
      xv.push_back(a);
      yv.push_back(b);
    } else if (t == 2) {
      dbg("2");
      if (uf.group_size(0) == (int)xv.size()) {
        cout << -1 << endl;
      } else {
        while (que.size()) {
          auto [_, a, b] = que.top();
          if (uf.is_same_group(a, b)) {
            que.pop();
          } else {
            break;
          }
        }

        auto [dist, a, b] = que.top();
        que.pop();
        cout << dist << endl;
        uf.unite(a, b);
        while (que.size() && get<0>(que.top()) == dist) {
          auto [_, c, d] = que.top();
          que.pop();
          uf.unite(d, c);
        }
      }
    } else {
      ll u, v;
      cin >> u >> v;
      dbg(t, u, v);
      u--;
      v--;
      if (uf.is_same_group(u, v)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
