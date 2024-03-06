#include <bits/stdc++.h>
#include <iterator>
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

class Tree {
public:
  Tree(int n) {
    int size = 1;
    while (size < n)
      size *= 2;
    tree.resize(size * 2 - 1);
    rep(i, tree.size()) tree[i] = map<ll, int>();
  }

  void set(int i, int v) {
    int node_i = tree.size() / 2 + i;
    tree[node_i].clear();
    tree[node_i][v] = 1;

    while (node_i) {
      node_i = (node_i - 1) / 2;
      op(node_i);
    }
  }

  map<ll, int> prod(int left, int right) {
    return prod(left, right, 0, 0, (tree.size() + 1) / 2);
  }

private:
  vector<map<ll, int>> tree;

  void op(int p) {
    int c1 = p * 2 + 1, c2 = p * 2 + 2;
    tree[p].clear();
    for (auto &[k, v] : tree[c1])
      tree[p][k] += v;
    for (auto &[k, v] : tree[c2])
      tree[p][k] += v;

    while (tree[p].size() > 2)
      tree[p].erase(begin(tree[p]));
  }
  map<ll, int> prod(int left, int right, int root, int l, int r) {
    if (right <= l || r <= left)
      return map<ll, int>();
    if (left <= l && r <= right)
      return tree[root];
    int mid = (l + r) / 2;
    map<ll, int> a = prod(left, right, root * 2 + 1, l, mid);
    map<ll, int> b = prod(left, right, root * 2 + 2, mid, r);
    map<ll, int> res;
    for (auto &[k, v] : a) {
      res[k] += v;
    }
    for (auto &[k, v] : b) {
      res[k] += v;
    }
    while (res.size() > 2)
      res.erase(begin(res));
    return res;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  Tree tree(n);
  rep(i, n) {
    tree.set(i, av[i]);
  }
  rep(_, q) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int p;
      ll x;
      cin >> p >> x;
      tree.set(p - 1, x);
    } else {
      int l, r;
      cin >> l >> r;
      map<ll, int> mp = tree.prod(l-1, r);
      if (mp.size() < 2)
        cout << 0 << endl;
      else
        cout << begin(mp)->second << endl;
    }
  }
  return 0;
}
