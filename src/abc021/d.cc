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

template <ll P> class ModCombi {
public:
  /** [0, right)内のi, jについてiCjを計算できる。
   */
  ModCombi(int right) {
    fact.resize(right);
    inv_fact.resize(right);
    for (ll i = 0; i < right; i++) {
      if (i == 0) {
        fact[0] = 1;
        inv_fact[0] = modinv(1);
      } else {
        fact[i] = i * fact[i - 1] % P;
        inv_fact[i] = modinv(i) * inv_fact[i - 1] % P;
      }
    }
    dbg(fact);
    dbg(inv_fact);
  }
  /**
   * nCr
   */
  ll c(int n, int r) { return fact[n] * inv_fact[n - r] % P * inv_fact[r] % P; }

private:
  vector<ll> fact, inv_fact;

private:
  /** aの逆元を返す。
   */
  ll modinv(ll a) {
    // mod + の前にa % modをするのは、とても小さい負の数が返されるため。
    dbg(a, extgcd(a, P));
    return (P + extgcd(a, P).first % P) % P;
  }
  /**
   * ax + by = gcd(a, b)の x, yを求める。
   * 拡張ユークリッドの互除法のx, yの候補はある。
   * 実装の参照元は、プログラミングコンテストチャレンジブック第二版。
   */
  pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0)
      return {1, 0};
    auto [x, y] = extgcd(b, a % b);
    return {y, x - a / b * y};
  }
};

int main() {
  ll n, k;
  const ll mod = 1000000007ll;
  cin >> n >> k;
  ModCombi<mod> com(n + k);
  cout << com.c(n + k - 1, k) << endl;
  return 0;
}
