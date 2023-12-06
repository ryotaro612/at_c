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

const ll mod = 998244353ll;
const ll MOD = 1000000007ll;

Mod<MOD> get_hash(int pos) {
  int rest = pos;
  Mod<MOD> base = 1;
  while (rest) {
    int step = 0;
    Mod<MOD> forward = mod;
    while ((1 << (step + 1)) <= rest) {
      step++;
      forward *= forward;
    }
    rest -= (1 << step);
    base *= forward;
  }
  return base;
}

int main() {
  ll n, q;
  string s;
  cin >> n >> q >> s;

  Bit<Mod<MOD>> bit(n), rev_bit(n);
  rep(i, n) {
    Mod<MOD> sm = s[i], rev_sm = s[n - 1 - i];
    bit.add(i, sm * get_hash(i));
    rev_bit.add(i, rev_sm * get_hash(i));
  }

  rep(i, q) {
    dbg(i);
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      char c;
      cin >> x >> c;
      Mod<MOD> ascii = c;
      --x;
      bit.update(x, ascii * get_hash(x));
      rev_bit.update(n - 1 - x, ascii * get_hash(n - 1 - x));
    } else {
      int l, r;
      cin >> l >> r;
      if (l == r) {
        cout << "Yes" << endl;
        continue;
      }
      r--;
      l--;
      int length = r - l + 1;
      Mod<MOD> left = bit.sum_range(l, l + length / 2);
      Mod<MOD> left_hash = left / get_hash(l);
      dbg(l, l + length / 2);
      Mod<MOD> right;
      int r_l = l + length / 2;
      if (length % 2) {
        r_l++;
      }
      int r_r = r_l + length / 2 - 1;
      right = rev_bit.sum_range(n - 1 - r_r, n - 1 - r_r + length / 2);
      dbg(n - 1 - r_r, n - 1 - r_r + length / 2);
      Mod<MOD> right_hash = right / get_hash(n - 1 - r_r);
      if (left_hash == right_hash)
        cout << "Yes";
      else
        cout << "No";
      cout << endl;
    }
  }
  // Bit<Mod<MOD>> temp(n), rev_temp(n);
  // string a = "abccccb";
  // rep(i, a.size()) {
  //   temp.update(i, Mod<MOD>(a[i]) * get_hash(i));
  //   rev_temp.update(i, Mod<MOD>(a[n-1-i]) * get_hash(i));
  // }  
  // rep(i, n) {
  //   dbg(bit.get(i));
  //   dbg(temp.get(i));
  //   dbg("---");
  // }
  // rep(i, n) {
  //   dbg(rev_bit.get(i));
  //   dbg(rev_temp.get(i));
  //   dbg("---");
  // }  


  return 0;
}
