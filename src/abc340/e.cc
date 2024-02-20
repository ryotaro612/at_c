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
template <typename S, typename F> class LazySegTree {
public:
  /** 遅延セグメント木
   * Sはノードの型で、_eはノードの初期値。
   * Fは遅延要素の型で、_idはデフォルトの値。
   */
  LazySegTree(int size, S _e, function<S(S, S)> _op, F _id,
              function<S(F, S)> _map, function<F(F, F)> _combination)
      : e(_e), op(_op), id(_id), map(_map), combination(_combination) {
    int n_nodes = 1;
    while (n_nodes < size)
      n_nodes *= 2;
    n_nodes = n_nodes * 2 - 1;
    tree.resize(n_nodes, e);
    lazy.resize(n_nodes, id);
  }

  void apply(int left, int right, F f) {
    apply(left, right, f, 0, 0, (tree.size() + 1) / 2);
  }

  S get(int node) { return prod(node, node + 1, 0, 0, (tree.size() + 1) / 2); }

private:
  vector<S> tree;
  S e;
  function<S(S, S)> op;
  F id;
  function<S(F, S)> map;
  vector<F> lazy;
  function<F(F, F)> combination;

  void apply(int left, int right, F f, int node, int leaf_l, int leaf_r) {
    push_down(node);
    if (leaf_r <= left || right <= leaf_l)
      return;
    if (left <= leaf_l && leaf_r <= right) {
      lazy[node] = f;
      push_down(node);
      return;
    }
    int mid = (leaf_l + leaf_r) / 2;
    apply(left, right, f, node * 2 + 1, leaf_l, mid);
    apply(left, right, f, node * 2 + 2, mid, leaf_r);
    tree[node] = op(tree[node * 2 + 1], tree[node * 2 + 2]);
  }

  S prod(int left, int right, int node, int leaf_l, int leaf_r) {
    push_down(node);
    if (leaf_r <= left || right <= leaf_l)
      return e;
    if (left <= leaf_l && leaf_r <= right) {
      return tree[node];
    }
    int mid = (leaf_l + leaf_r) / 2;
    S l = prod(left, right, node * 2 + 1, leaf_l, mid);
    S r = prod(left, right, node * 2 + 2, mid, leaf_r);
    return op(l, r);
  }

  void push_down(int node) {
    tree[node] = map(lazy[node], tree[node]);
    if (node < static_cast<int>(tree.size()) / 2) {
      lazy[node * 2 + 1] = combination(lazy[node], lazy[node * 2 + 1]);
      lazy[node * 2 + 2] = combination(lazy[node], lazy[node * 2 + 2]);
    }
    lazy[node] = id;
  }
};
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<int> bv(m);
  rep(i, m) cin >> bv[i];

  LazySegTree<ll, ll> tree(
      n, 0, [](ll a, ll b) { return a + b; }, 0,
      [](ll f, ll s) { return f + s; }, [](ll a, ll b) { return a + b; });
  rep(i, n) {
    // dbg(i, "n");
    tree.apply(i, i + 1, av[i]);
  }

  rep(i, m) {
    dbg(i);
    ll n_balls = tree.get(bv[i]);
    tree.apply(bv[i], bv[i] + 1, -n_balls);
    tree.apply(0, n, n_balls / n);
    n_balls -= n_balls / n * n;
    if (n_balls == 0)
      continue;
    if (n_balls <= n - (bv[i] + 1ll)) {
      tree.apply(bv[i] + 1ll, bv[i] + 1ll + n_balls, 1);
    } else {
      tree.apply(bv[i] + 1ll, n, 1);
      n_balls -= n - (bv[i] + 1ll);
      tree.apply(0, n_balls, 1);
    }
    //rep(j, n) { cout << tree.get(j) << " \n"[j == n - 1]; }
  }

  rep(i, n) { cout << tree.get(i) << " \n"[i == n - 1]; }

  return 0;
}
