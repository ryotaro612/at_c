#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
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

pair<ll, ll> ext_gcd(ll a, ll b) {
  if (a < 0) {
    auto [x, y] = ext_gcd(-a, b);
    return {-x, y};
  }
  if (b < 0) {
    auto [x, y] = ext_gcd(a, -b);
    return {x, -y};
  }
  if (a < b) {
    auto [x, y] = ext_gcd(b, a);
    return {y, x};
  }
  if (b == 0)
    return {1, 0};
  auto [x, y] = ext_gcd(b, a % b);
  return {y, x - a / b * y};
}

ll modinv(ll a, ll mod) {
  auto [x, y] = ext_gcd(a, mod);
  return (x % mod + mod) % mod;
}

ll pow_mod(ll x, ll n, ll mod) {
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

const ll MOD = 100000007ll;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n == 1) {
    cout << s << endl;
    return 0;
  }

  vector<ll> forward(n, 0), backward(n, 0);
  rep(i, n) {
    if (i == 0) {
      forward[i] = s[i];
    } else {
      forward[i] = forward[i - 1] * MOD + s[i];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      backward[i] = s[i];
    } else {
      backward[i] = backward[i + 1] * MOD + s[i];
    }
  }

  for (int i = n / 2; i < n; i++) {
    dbg(i);
    int len = n - i;
    if (len * 2 <= n) {
      ll offset = 0;
      if (i - 1 - len >= 0) {
        offset = forward[i - 1 - len] * pow_mod(MOD, len, LLONG_MAX);
      }
      if (backward[i] == forward[i - 1] - offset) {

        string half = s.substr(0, i);
        dbg("ok", half);
        string b(half);
        reverse(b.begin(), b.end());
        cout << half + b << endl;
        return 0;
      }
    }
    if (i < n - 1 && (len - 1) * 2 + 1 <= n) {

      ll offset = 0;
      if (i - 1 - (len - 1) >= 0) {
        offset = forward[i - 1 - (len - 1)] * pow_mod(MOD, len - 1, LLONG_MAX);
      }
      if (backward[i + 1] == forward[i - 1] - offset) {
        dbg("ok2");
        string half = s.substr(0, i);
        string b(half);
        reverse(b.begin(), b.end());
        cout << half + s[i] + b << endl;
        return 0;
      }
    }
  }

  string ss(s);
  ss.pop_back();
  reverse(ss.begin(), ss.end());
  cout << s << ss << endl;
  return 0;
}
