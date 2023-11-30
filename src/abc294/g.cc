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

template <typename E> class Bit {
public:
  Bit(int n) : bit(vector<E>(n + 1, 0)) {}

  E get(int i) { return sum(i + 1) - sum(i); }

  /**
   *  sum of arr[0,to)
   */
  E sum(int to) {
    E res = 0;
    while (to) {
      res += bit[to];
      to -= to & -to;
    }
    return res;
  }
  /**
   * sum of arr[from,to)
   */
  E sum_range(int from, int to) { return sum(to) - sum(from); }

  void update(int pos, E v) {
    add(pos, -get(pos));
    add(pos, v);
  }

  void add(int pos, E v) {
    pos++;
    while (pos < static_cast<int>(bit.size())) {
      bit[pos] += v;
      pos += pos & -pos;
    }
  }

private:
  vector<E> bit;
};

struct Edge {
  int idx, to;
  ll w;
};

void calc_depths(int node, vector<vector<Edge>> &g, vector<int> &depths) {
  for (auto edge : g[node]) {
    if (depths[edge.to] == -1) {
      depths[edge.to] = depths[node] + 1;
      calc_depths(edge.to, g, depths);
    }
  }
}
void find_ancestors(int node, vector<vector<Edge>> &g,
                    vector<vector<int>> &ancestors) {
  for (auto edge : g[node]) {
    int base = edge.to;
    if (ancestors[base].size() == 0) {
      ancestors[base].push_back(base);
      ancestors[base].push_back(node);
      while (ancestors[base].size() - 1 <
             ancestors[ancestors[base].back()].size()) {
        ancestors[base].push_back(
            ancestors[ancestors[base].back()][ancestors[base].size() - 1]);
      }
      find_ancestors(base, g, ancestors);
    }
  }
}

int find_lca(int u, int v, vector<vector<int>> &ancestors,
             vector<int> &depths) {
  if (u == v)
    return u;
  if (depths[v] < depths[u])
    swap(u, v);

  if (depths[v] == depths[u]) {
    int i = ancestors[v].size() - 1;
    while (ancestors[v][i] == ancestors[u][i] && i > 1)
      i--;
    return find_lca(ancestors[u][i], ancestors[v][i], ancestors, depths);
  } else {
    int i = 0;
    while (i + 1 < (int)ancestors[v].size() &&
           depths[u] < depths[ancestors[v][i + 1]])
      i++;
    if (i + 1 < (int)ancestors[v].size() &&
        depths[ancestors[v][i + 1]] == depths[u]) {
      return find_lca(u, ancestors[v][i + 1], ancestors, depths);
    } else {
      return find_lca(u, ancestors[v][i], ancestors, depths);
    }
  }
}

class LowestCommonAncestor {
public:
  LowestCommonAncestor(int root, vector<vector<int>> _tree) {
    tree =_tree;
    
    depths.resize(n_nodes(), -1);
    depths[root] = 0;
    measure_depth(root);

    ancestors.resize(n_nodes());
    ancestors[root].push_back(root);
    find_ancestors(root);
  }

  int find_lca(int u, int v) {
    if (u == v)
      return u;
    if (depths[v] < depths[u])
      swap(u, v);

    if (depths[v] == depths[u]) {
      int i = ancestors[v].size() - 1;
      while (ancestors[v][i] == ancestors[u][i] && i > 1)
        i--;
      return find_lca(ancestors[u][i], ancestors[v][i]);
    } else {
      int i = 0;
      while (i + 1 < (int)ancestors[v].size() &&
             depths[u] < depths[ancestors[v][i + 1]])
        i++;
      if (i + 1 < (int)ancestors[v].size() &&
          depths[ancestors[v][i + 1]] == depths[u])
        return find_lca(u, ancestors[v][i + 1]);
      else
        return find_lca(u, ancestors[v][i]);
    }
  }

private:
  vector<vector<int>> tree;
  vector<int> depths;
  vector<vector<int>> ancestors;

  void measure_depth(int node) {
    for (auto neighbor : tree[node]) {
      if (depths[neighbor] == -1) {
        depths[neighbor] = depths[node] + 1;
        measure_depth(neighbor);
      }
    }
  }

  int n_nodes() { return tree.size(); }

  void find_ancestors(int node) {
    for (auto neighbor : tree[node]) {
      if (ancestors[neighbor].size() == 0) {
        ancestors[neighbor].push_back(neighbor);
        ancestors[neighbor].push_back(node);
        while (ancestors[neighbor].size() - 1 <
               ancestors[ancestors[neighbor].back()].size()) {
          ancestors[neighbor].push_back(
              ancestors[ancestors[neighbor].back()]
                       [ancestors[neighbor].size() - 1]);
        }
        find_ancestors(neighbor);
      }
    }
  }
};
void order_edges(int &idx, int node, vector<vector<Edge>> &g, Bit<ll> &bit,
                 vector<int> &line, unordered_map<int, int> &forward,
                 unordered_map<int, int> &backward) {
  for (auto edge : g[node]) {
    if (forward.contains(edge.idx))
      continue;

    forward[edge.idx] = idx++;
    line[edge.to] = idx;
    bit.add(forward[edge.idx], edge.w);
    // dbg(edge.w, forward[edge.idx], bit.get(forward[edge.idx]));
    order_edges(idx, edge.to, g, bit, line, forward, backward);
    backward[edge.idx] = idx++;
    bit.add(backward[edge.idx], -edge.w);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<Edge>> g(n);
  vector<ll> wv(n - 1);
  vector<vector<int>> tree(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v >> wv[i];
    g[--u].push_back({i, --v, wv[i]});
    g[v].push_back({i, u, wv[i]});

    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  LowestCommonAncestor lca(0, tree);
  vector<vector<int>> ancestors(n);
  vector<int> depths(n, -1);
  calc_depths(depths[0] = 0, g, depths);
  ancestors[0].push_back(0);
  find_ancestors(0, g, ancestors);

  unordered_map<int, int> forward, backward;
  vector<int> line(n, -1);
  vector<ll> order;

  Bit<ll> bit((n - 1) * 2);
  int idx = 0;
  line[0] = idx;
  order_edges(idx, 0, g, bit, line, forward, backward);

  // rep(i, (n-1)*2) {
  //   dbg(bit.get(i));
  // }

  int q;
  cin >> q;
  rep(_, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      ll w;
      cin >> i >> w;
      --i;
      bit.update(forward[i], w);
      bit.update(backward[i], -w);
    } else {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      //int ancestor = find_lca(u, v, ancestors, depths);
      int ancestor = lca.find_lca(u, v);
      // dbg(u, v, ancestor);
      // rep(i, n - 1) { dbg(bit.get(i)); }

      // dbg(u, line[u], bit.sum(line[u]));
      // dbg(u, line[v], bit.sum(line[v]));
      // dbg(ancestor, line[ancestor], bit.sum(line[ancestor]));
      cout << bit.sum(line[u]) + bit.sum(line[v]) -
                  2ll * bit.sum(line[ancestor])
           << endl;
    }
  }
  return 0;
}
