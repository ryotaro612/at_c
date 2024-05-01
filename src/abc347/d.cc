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
int main() {
  ll a, b;
  ll c;
  cin >> a >> b >> c;

  ll nbits_c = 0;
  for (ll i = 0; c >> i; i++) {
    if ((c >> i) & 1) {
      nbits_c++;
    }
  }
  if (!((a + b - nbits_c) % 2 == 0 && (a + b - nbits_c) >= 0)) {
    cout << -1 << endl;
    return 0;
  }
  ll x = 0, y = 0;
  dbg(nbits_c);
  for (ll i = 0; (a > 0 || b > 0); i++) {
    if(i == 60) {
      cout << -1 << endl;
      return 0;
    }
    dbg(i, a, b, nbits_c);

    if (c & (1ll << i)) {
      if (a > b) {
        a--;
        x |= (1ll << i);
      } else {
        b--;
        y |= (1ll << i);
      }
      nbits_c--;
    } else {
      if (a + b > nbits_c) {
        x |= (1ll << i);
        y |= (1ll << i);
        a--;
        b--;
      }
    }
  }
  dbg(x ^ y);
  if ((x ^ y) == c) {
    cout << x << " " << y << endl;
  } else
    cout << -1 << endl;

  return 0;
}
