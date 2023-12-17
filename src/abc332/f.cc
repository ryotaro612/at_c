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
template <ll P> class Mod {
public:
  Mod() : v(0) {}
  Mod(ll v_) : v((v_ % P + P) % P) {}
  ll get() { return v; }
  Mod<P> operator*(Mod<P> &a) { return Mod<P>(v * a.v % P); }
  Mod<P> operator*(ll &b) { return Mod<P>(v * b % P); }
  friend Mod<P> operator+(const Mod<P> &lhs, const ll &rhs) {
    return Mod((lhs.v + rhs) % P);
  }
  friend Mod<P> operator+(const Mod<P> &lhs, const Mod<P> &rhs) {
    return Mod((lhs.v + rhs.v) % P);
  }
  friend Mod<P> operator-(const Mod<P> &lhs, const Mod<P> &rhs) {
    ll res = lhs.v - rhs.v;
    if (res < 0)
      res += P;
    return Mod<P>(res);
  }
  Mod<P> operator-() { return (-v + P) % P; }
  friend Mod<P> operator*(const Mod<P> &lhs, const Mod<P> &rhs) {
    return Mod<P>(lhs.v * rhs.v % P);
  }
  friend Mod<P> operator/(const Mod<P> &lhs, const Mod<P> &rhs) {
    ll b = P, u = 1, vv = 0, a = rhs.v;
    while (b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * vv;
      swap(u, vv);
    }
    u %= P;
    if (u < 0)
      u += P;
    return lhs.v * u % P;
  }
  Mod<P> &operator=(const ll &number) {
    v = number;
    return *this;
  }
  Mod<P> &operator+=(const Mod &rhs) {
    v += rhs.v;
    v %= P;
    return *this;
  }
  Mod<P> &operator-=(const Mod &rhs) {
    v -= rhs.v;
    if (v < 0)
      v += P;
    return *this;
  }
  Mod<P> &operator*=(const Mod &rhs) {
    v *= rhs.v;
    v %= P;
    return *this;
  }
  Mod<P> &operator++() {
    v++;
    v %= P;
    return *this;
  }
  friend bool operator==(const Mod<P> &lhs, const int &rhs) {
    return lhs.v == rhs;
  }
  friend bool operator==(const Mod<P> &lhs, const Mod<P> &rhs) {
    return lhs.v == rhs.v;
  }
  friend ostream &operator<<(ostream &os, const Mod<P> &mod) {
    os << mod.v;
    return os;
  }
  friend istream &operator>>(istream &is, Mod<P> &mod) {
    is >> mod.v;
    return is;
  }

  Mod<P> pow(ll n) {
    ll res = 1ll;
    ll x = v;
    while (n) {
      if (n & 1) {
        res *= x;
        res %= P;
      }
      n >>= 1;
      x *= x;
      x %= P;
    }
    return res;
  }

private:
  ll v;
};

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
const ll MOD = 998244353ll;

pair<ll, ll> ext_gcd(ll a, ll b) {
  if (b == 0)
    return {1, 0};
  auto [x, y] = ext_gcd(b, a % b);
  return {y, x - a / b * y};
}
ll mod_inv(ll a) {
  auto [x, _] = ext_gcd(a, MOD);
  return (x % MOD + MOD) % MOD;
}
ll mod_div(ll a, ll b) { return a * mod_inv(b) % MOD; }
// typename OP, function<E> IE, typename , typename MP, typename C, typename ID
template <typename S, typename F> class LazySegTree {
public:
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
static Mod<MOD> fstos(pair<Mod<MOD>, Mod<MOD>> f, Mod<MOD> s) {
  return f.first * s + f.second;
}

static pair<Mod<MOD>, Mod<MOD>> combi(pair<Mod<MOD>, Mod<MOD>> f,
                                      pair<Mod<MOD>, Mod<MOD>> g) {
  return {g.first * f.first, g.second * f.first + f.second};
}

static Mod<MOD> opp(Mod<MOD> a, Mod<MOD> b) { return a + b; }

int main() {
  dbg("doge");
  int n, m;
  cin >> n >> m;

  LazySegTree<Mod<MOD>, pair<Mod<MOD>, Mod<MOD>>> tree(n, 0, opp, {1, 0}, fstos,
                                                       combi);
  dbg("doge");
  rep(i, n) {
    Mod<MOD> a;
    cin >> a;

    tree.apply(i, i + 1, {0, a});
    dbg(i, tree.get(i));
  }
  rep(_, m) {
    ll l, r, x;
    cin >> l >> r >> x;
    Mod<MOD> p = mod_inv(r - l + 1);

    tree.apply(--l, r, {Mod<MOD>(1) - p, Mod<MOD>(x) * p});
  }
  dbg("doge");
  rep(i, n) { cout << tree.get(i) << " \n"[i == n - 1]; }

  return 0;
}
