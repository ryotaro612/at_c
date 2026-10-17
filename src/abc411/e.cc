#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<ll>> am(n, vector<ll>(6));
  vector<int> ai(n, 0);
  multiset<tuple<int, int>> order;
  ll const MOD = 998244353ll;
  vector<int> progress(7, 0);
  progress[0] = n;
  ll max_value = 0;
  rep(i, n) {
    rep(j, 6) { cin >> am[i][j]; }
    sort(am[i].begin(), am[i].end());

    max_value = max(max_value, am[i][0]);

    rep(j, 6) { order.insert({am[i][j], i}); }
  }

  while (order.size() && get<0>(*order.begin()) <= max_value) {
    auto [a, r] = *order.begin();
    order.erase(order.begin());
    progress[ai[r]]--;
    ai[r]++;
    progress[ai[r]]++;
  }
  dbg(max_value, progress);

  Mod<MOD> res = 0;
  Mod<MOD> prob = 1;
  rep(i, 7) { prob *= (Mod<MOD>(i) / Mod<MOD>(6)).pow(progress[i]); }
  res += prob * Mod<MOD>(max_value);
  Mod<MOD> last_prob = prob;

  while (order.size()) {
    auto [a, r] = *order.begin();
    order.erase(order.begin());
    progress[ai[r]]--;
    ai[r]++;
    progress[ai[r]]++;

    while (order.size() && get<0>(*order.begin()) == a) {
      auto [_, r2] = *order.begin();
      order.erase(order.begin());
      progress[ai[r2]]--;
      ai[r2]++;
      progress[ai[r2]]++;
    }
    dbg(a, progress);
    prob = 1;
    rep(i, 7) { prob *= (Mod<MOD>(i) / Mod<MOD>(6)).pow(progress[i]); }
    res += (prob - last_prob) * Mod<MOD>(a);
    last_prob = prob;
  }
  cout << res.get() << endl;

  return 0;
}

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int n;
//   cin >> n;
//   vector<vector<ll>> am(n, vector<ll>(6));
//   vector<int> ai(n, 0);
//   set<tuple<int, int>> order;
//   ll max_value = 0;
//   vector<int> progress(6, 0);
//   rep(i, n) {
//     rep(j, 6) { cin >> am[i][j]; }
//     sort(am[i].begin(), am[i].end());
//     while (i < 6 && am[i][0] == am[i][ai[i]]) {
//       ai[i]++;
//     }
//     max_value = max(max_value, am[i][ai[i]]);
//     progress[ai[i]]++;
//     for (int j = ai[i]; j < 6; j++) {
//       order.insert({am[i][j], i});
//     }
//   }
//   ll const MOD = 998244353ll;
//   Mod<MOD> res = 0;
//   Mod<MOD> prob = 1;
//   rep(i, 6) { prob *= (Mod<MOD>(i + 1) / Mod<MOD>(6)).pow(progress[i]); }
//   res += prob * Mod<MOD>(max_value);
//   Mod<MOD> last_prob = prob;

//   while (order.size()) {
//     auto [a, r] = *order.begin();
//     order.erase(order.begin());
//     progress[ai[r]]--;
//     ai[r]++;
//     progress[ai[r]]++;

//     while (order.size() && get<0>(*order.begin()) == a) {
//       auto [a2, r2] = *order.begin();
//       order.erase(order.begin());
//       progress[ai[r2]]--;
//       progress[r2]++;
//       progress[ai[r2]]++;
//     }
//     prob = 1;
//     rep(i, 6) { prob *= (Mod<MOD>(i + 1) / Mod<MOD>(6)).pow(progress[i]); }
//     res += (prob - last_prob) * Mod<MOD>(a);
//     last_prob = prob;
//   }
//   cout << res.get() << endl;

//   return 0;
// }
