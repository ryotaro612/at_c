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

ll my_pow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  vector<ll> ranges = {9, 9 * 9};

  rep(_, t) {
    ll k;
    cin >> k;
    int d = 1;
    for (; my_pow(9, d) < k; d++) {
      k -= my_pow(9, d);
    }
    string res = "";
    for (int i = 1; i < 10; i++) {
      if (my_pow(9, d - 1) < k) {
        k -= my_pow(9, d - 1);
      } else {
        res.push_back(i + '0');
        break;
      }
    }
    while ((int)res.size() < d) {
      int prev = res.back() - '0';
      rep(i, 10) {
        if (prev == i)
          continue;

        if (my_pow(9, d - res.size() - 1) < k) {
          k -= my_pow(9, d - res.size() - 1);
        } else {
          res.push_back(i + '0');
          break;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
