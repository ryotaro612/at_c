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

template <typename S> class SegTree {
public:
  SegTree(int size, function<S(S, S)> _op, S _e) : op(_op), e(_e) {
    int n_nodes = 1;
    while (n_nodes < size)
      n_nodes *= 2;
    tree.resize(n_nodes * 2 - 1, e);
  }

  void set(int i, S v) {
    int node = tree.size() / 2 + i;
    tree[node] = v;
    while (node > 0) {
      node = (node - 1) / 2;
      tree[node] = op(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
  }

  S get(int i) { return prod(i, i + 1); }

  S prod(int left, int right) {
    return prod(left, right, 0, 0, (tree.size() + 1) / 2);
  }

private:
  function<S(S, S)> op;
  vector<S> tree;
  S e;

  S prod(int left, int right, int node, int leaf_l, int leaf_r) {
    if (leaf_r <= left || right <= leaf_l)
      return e;
    if (left <= leaf_l && leaf_r <= right)
      return tree[node];
    int mid = (leaf_l + leaf_r) / 2;
    S l = prod(left, right, node * 2 + 1, leaf_l, mid);
    S r = prod(left, right, node * 2 + 2, mid, leaf_r);
    return op(l, r);
  }
};

ll op(ll a, ll b) { return max(a, b); }

ll op_min(ll a, ll b) { return min(a, b); }

int main() {
  int n;
  cin >> n;
  vector<ll> pv(n), res(n, 10000000000ll);
  rep(i, n) cin >> pv[i];
  ll e = -100000000ll;
  SegTree<ll> tree(n + 1, op, e);

  rep(i, n) {
    res[i] = min(res[i], pv[i] + (i + 1) - tree.prod(0, pv[i]));
    tree.set(pv[i], pv[i] + (i + 1));
  }
  dbg(res[0]);
  tree = SegTree<ll>(n + 1, op, e);
  for (int i = n - 1; i >= 0; i--) {
    res[i] = min(res[i], pv[i] - (i + 1) - tree.prod(0, pv[i]));
    tree.set(pv[i], pv[i] - (i + 1));
  }
  dbg(res[0]);
  tree = SegTree<ll>(n + 1, op_min, -e);
  rep(i, n) {
    res[i] = min(res[i], -(pv[i] - (i + 1)) + tree.prod(pv[i], n + 1));
    tree.set(pv[i], pv[i] - (i + 1));
  }
  dbg(res[0]);
  tree = SegTree<ll>(n + 1, op_min, -e);
  for (int i = n - 1; i >= 0; i--) {
    res[i] = min(res[i], -(pv[i] + (i + 1)) + tree.prod(pv[i] + 1, n + 1));
    tree.set(pv[i], pv[i] + (i + 1));
  }
  dbg(res[0]);
  rep(i, n) cout << res[i] << " \n"[i == n - 1];

  return 0;
}
