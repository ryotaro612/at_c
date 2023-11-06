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

class LazyRMQ {
public:
  LazyRMQ(int _size, ll _mx) : mx(_mx) {
    int i = 1;
    while (i < _size)
      i *= 2;
    tree.resize(i * 2 - 1);
    fill(begin(tree), end(tree), 0);
    lazy.resize(i * 2 - 1);
    fill(begin(lazy), end(lazy), 0);
  }

  void add(int left, int right, ll v) { add(left, right, 0, 0, n_leaves(), v); }
  ll query(int left, int right) { return query(left, right, 0, 0, n_leaves()); }

private:
  vector<ll> tree;
  vector<ll> lazy;
  ll mx;

  void add(int left, int right, int root, int leaf_l, int leaf_r, int v) {
    force(root, leaf_l, leaf_r);
    if (leaf_r <= left || right <= leaf_l)
      return;
    if (left <= leaf_l && leaf_r <= right) {
      lazy[root] += v;
      // 以下でtree[root]を更新するから、addのパラメタrootの値は最新の値でなければならない。
      force(root, leaf_l, leaf_r);
      return;
    }
    add(left, right, root * 2 + 1, leaf_l, (leaf_l + leaf_r) / 2, v);
    add(left, right, root * 2 + 2, (leaf_l + leaf_r) / 2, leaf_r, v);
    tree[root] = min(tree[root * 2 + 1], tree[root * 2 + 2]);
  }

  ll query(int left, int right, int root, int leaf_l, int leaf_r) {
    force(root, leaf_l, leaf_r);
    if (leaf_r <= left || right <= leaf_l)
      return mx;
    if (left <= leaf_l && leaf_r <= right)
      return tree[root];
    ll min_l = query(left, right, root * 2 + 1, leaf_l, (leaf_l + leaf_r) / 2);
    ll min_r = query(left, right, root * 2 + 2, (leaf_l + leaf_r) / 2, leaf_r);
    return min(min_l, min_r);
  }
  int n_leaves() { return (tree.size() + 1) / 2; }

  void force(int root, int left, int right) {
    if (lazy[root] == 0)
      return;

    tree[root] += lazy[root];
    if (right - left > 1) {
      lazy[root * 2 + 1] += lazy[root];
      lazy[root * 2 + 2] += lazy[root];
    }
    lazy[root] = 0;
  }
};

class Db {
public:
  Db(int size) : tree(size, 1000000000ll) {}

  void add(int left, int right, int v) { tree.add(left, right, -v); }
  ll query(int left, int right) { return -tree.query(left, right); }

private:
  LazyRMQ tree;
};

int main() {
  int n, d, w;
  cin >> n >> d >> w;
  vector<int> tv(n), xv(n);
  int mx_x = -1;
  int mx_t = -1;
  rep(i, n) {
    cin >> tv[i] >> xv[i];
    mx_x = max(mx_x, xv[i]);
    mx_t = max(mx_t, tv[i]);
  }
  vector<vector<pair<int, int>>> pairs(mx_t + 1);
  rep(i, n) {
    pairs[max(0, tv[i] - d)].push_back({xv[i], 1});
    pairs[tv[i]].push_back({xv[i], -1});
  }
  ll res = 0;
  LazyRMQ temp2(10, 1000000ll);
  dbg(temp2.query(0, 10));
  temp2.add(0, 4, -1);
  dbg(temp2.query(3, 4));
  
  Db temp(10);
  dbg(temp.query(0, 10));
  temp.add(0, 4, 1);
  dbg(temp.query(3, 4));
  Db db(mx_x + 1);
  rep(i, mx_t + 1) {
    for (auto [x, delta] : pairs[i]) {
      db.add(max(0, x - w), x, delta);
    }
    res = max(res, db.query(0, mx_x + 1));
  }
  cout << res << endl;
  return 0;
}

class LstNode {
public:
  int n;
  vector<int> l, r, m;
  LstNode() : LstNode(0) {}
  LstNode(int n_) : n(n_) {
    l.resize(2);
    r.resize(2);
    m.resize(2);
    l[0] = r[0] = m[0] = n;
    l[1] = r[1] = m[1] = 0;
  }

  void flip() {
    swap(l[0], l[1]);
    swap(r[0], r[1]);
    swap(m[0], m[1]);
  }
};

LstNode merge(LstNode &left, LstNode &right) {
  LstNode res(left.n + right.n);

  rep(t, 2) {
    res.l[t] = left.l[t];
    if (left.n == left.l[t])
      res.l[t] += right.l[t];

    res.r[t] = right.r[t];
    if (right.n == right.r[t])
      res.r[t] += left.r[t];

    res.m[t] = max({left.m[t], right.m[t], left.r[t] + right.l[t]});
  }
  return res;
}

class LazySegmentTree {

public:
  vector<LstNode> tree;
  vector<int> lazy;
  LazySegmentTree(int n) {
    int size = 1;
    while (size < n)
      size *= 2;
    tree.resize(size * 2 - 1);
    lazy = vector<int>(size * 2 - 1, 0);
    for (int i = 0, a = 1; i < (int)tree.size(); i++) {
      tree[i] = LstNode(size);
      if (i == a * 2 - 2) {
        size /= 2;
        a *= 2;
      }
    }
  }
  void flip(int left, int right) { flip(left, right, 0, 0, n_leaves()); }
  LstNode query(int left, int right) {
    return query(left, right, 0, 0, n_leaves());
  }

  void debug() {
    rep(i, tree.size()) {
      dbg(i, lazy[i], tree[i].n, tree[i].l[0], tree[i].r[0], tree[i].m[0],
          tree[i].l[1], tree[i].r[1], tree[i].m[1]);
    }
  }

private:
  void flip(int from, int to, int root, int left, int right) {
    eval(root, left, right);
    if (right <= from || to <= left)
      return;

    if (from <= left && right <= to) {
      lazy[root]++;
      eval(root, left, right);
      return;
    }

    flip(from, to, root * 2 + 1, left, (left + right) / 2);
    flip(from, to, root * 2 + 2, (left + right) / 2, right);
    tree[root] = merge(tree[root * 2 + 1], tree[root * 2 + 2]);
  }
  LstNode query(int from, int to, int root, int left, int right) {
    eval(root, left, right);
    if (right <= from || to <= left)
      return LstNode();
    if (from <= left && right <= to)
      return tree[root];

    LstNode cand1 = query(from, to, root * 2 + 1, left, (left + right) / 2);
    LstNode cand2 = query(from, to, root * 2 + 2, (left + right) / 2, right);
    return merge(cand1, cand2);
  }

  void eval(int root, int left, int right) {
    if (lazy[root] == 0)
      return;
    if (lazy[root] % 2)
      tree[root].flip();
    if (right - left > 1) {
      lazy[root * 2 + 1] += lazy[root];
      lazy[root * 2 + 2] += lazy[root];
    }
    lazy[root] = 0;
  }

  int leftmost_leaf() { return (tree.size() + 1) / 2 - 1; }
  int n_leaves() { return (tree.size() + 1) / 2; }
};
