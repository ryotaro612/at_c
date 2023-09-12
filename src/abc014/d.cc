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

void dfs(int node, int height, int parent, vector<vector<int>> &g,
         vector<int> &heights, vector<int> &order, vector<int> &index) {
  heights.push_back(height);
  if (index[node] == -1)
    index[node] = order.size();
  order.push_back(node);

  for (auto child : g[node]) {
    if (child != parent) {
      dfs(child, height + 1, node, g, heights, order, index);
      heights.push_back(height);
      order.push_back(node);
    }
  }
}
template <typename T> class RMQ {
public:
  RMQ(int size, T inf_) {
    int n_leaves = 1;
    while (n_leaves < size)
      n_leaves *= 2;
    inf = inf_;
    tree.resize(n_leaves * 2 - 1, inf);
  }

  void update(int k, T a) {
    int node = leftmost_leaf() + k;
    tree[node] = a;
    while (node > 0) {
      node = (node - 1) / 2;
      tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
  }

  T query(int from, int to) { return query(from, to, 0, 0, n_leaves()); }

private:
  vector<T> tree;
  T inf;
  int leftmost_leaf() { return (tree.size() + 1) / 2 - 1; }
  int n_leaves() { return (tree.size() + 1) / 2; }

  T query(int from, int to, int root, int left, int right) {
    if (right <= from || to <= left)
      return inf;
    if (from <= left && right <= to)
      return tree[root];
    T left_v = query(from, to, root * 2 + 1, left, (left + right) / 2);
    T right_v = query(from, to, root * 2 + 2, (left + right) / 2, right);
    return min(left_v, right_v);
  }
};
int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int x, y;
    cin >> x >> y;
    g[--x].push_back(--y);
    g[y].push_back(x);
  }
  vector<int> heights, order, index(n, -1);
  dfs(0, 0, -1, g, heights, order, index);

  RMQ<pair<int, int>> rmq(heights.size(), {1000000, 1000000});
  rep(i, order.size()) { rmq.update(i, {heights[i], order[i]}); }

  int q;
  cin >> q;
  rep(_, q) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    pair<int, int> mini =
        rmq.query(min(index[a], index[b]), max(index[a], index[b]) + 1);
    int res =
        heights[index[a]] - mini.first + heights[index[b]] - mini.first + 1;
    cout << res << endl;
  }

  return 0;
}
