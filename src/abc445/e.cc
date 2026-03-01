#include <iostream>
#include <map>
#include <numeric>
#include <string>
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

ll my_pow_mod(ll x, ll n, ll mod) {
  ll res = 1ll;
  while (n) {
    if (n & 1) {
      res *= x;
      res %= mod;
    }

    n >>= 1;
    x *= x;
    x %= mod;
  }
  return res;
}

static ll const MOD = 998244353ll;
// A_iの素数の種類はすごいすくない
vector<ll> solve(vector<ll> &av, vector<ll> &lpf_vec) {
  int n = av.size();
  map<ll, ll> prime_exp_first, prime_exp_second;
  for (auto &a : av) {
    ll i = a;
    while (i > 1) {
      auto prime = lpf_vec[i];
      int counter = 0;
      while (i % prime == 0) {
        counter++;
        i /= prime;
      }
      if (counter > prime_exp_first[prime]) {
        prime_exp_second[prime] = prime_exp_first[prime];
        prime_exp_first[prime] = counter;

      } else if (counter > prime_exp_second[prime]) {
        prime_exp_second[prime] = counter;
      }
    }
  }

  ll total = 1ll;
  for (auto &[p, e] : prime_exp_first) {
    total *= my_pow_mod(p, e, MOD);
    total %= MOD;
  }
  dbg(av);
  dbg(total);
  vector<ll> res(n);
  rep(i, n) {
    dbg(i);
    Mod<MOD> e = total;
    int x = av[i];
    while (x > 1) {
      auto prime = lpf_vec[x];
      int counter = 0;
      while (x % prime == 0) {
        counter++;
        x /= prime;
      }
      if (counter == prime_exp_first[prime]) {
        auto div = Mod<MOD>(prime);
        if (counter == prime_exp_first[prime])
          e = e / (div.pow(prime_exp_first[prime] - prime_exp_second[prime]));
      }
    }
    res[i] = e.get();
  }

  return res;
}

vector<long long> linear_sieve(int n) {
  vector<long long> lpf(n, 0);
  iota(lpf.begin(), lpf.end(), 0);
  vector<long long> primes;
  for (int i = 2; i < n; i++) {
    if (lpf[i] == i)
      primes.push_back(i);
    for (auto &prime : primes) {
      if (prime * i >= n || lpf[i] < prime)
        break;
      lpf[prime * i] = prime;
    }
  }
  return lpf;
}

int main() {
  int t;
  cin >> t;
  vector<ll> lpf_vec = linear_sieve(1e7 + 1);
  rep(i, t) {
    int n;
    cin >> n;
    vector<ll> av(n);
    rep(j, n) cin >> av[j];
    auto ans = solve(av, lpf_vec);
    dbg(ans);
    rep(k, n) {
      cout << ans[k];
      if (k == n - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
  return 0;
}
