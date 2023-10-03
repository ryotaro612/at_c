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

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  LazySegmentTree tree(n);
  rep(i, n) {
    if (s[i] == '1')
      tree.flip(i, i + 1);
  }

  rep(a, q) {
    int c, l, r;
    cin >> c >> l >> r;
    if (c == 1)
      tree.flip(l - 1, r);
    else
      cout << tree.query(l - 1, r).m[1] << endl;
  }

  return 0;
}
