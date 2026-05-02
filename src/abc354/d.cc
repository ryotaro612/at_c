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
ll calc1(ll b, ll d) {
  if (b % 2ll == 0 && d % 2ll == 0) {
    return 3ll * (d - b) / 2ll;
  } else if (b % 2ll == 0 && d % 2ll) {
    return calc1(b, d - 1ll) + 2ll;
  } else if (b % 2ll && d % 2ll == 0) {
    return calc1(b + 1ll, d) + 1ll;
  } else
    return 3ll * (d - b) / 2ll;
}

ll calc2(ll b, ll d) {
  if (b % 2ll == 0 && d % 2ll == 0) {
    return 3ll * (d - b) / 2ll;
  } else if (b % 2ll == 0 && d % 2ll) {
    return calc2(b, d - 1ll) + 1ll;
  } else if (b % 2ll && d % 2ll == 0) {
    return calc2(b + 1ll, d) + 2ll;
  } else {
    return 3ll * (d - b) / 2ll;
  }
}
ll calc3(ll b, ll d) { return (d - b) * 2ll - calc1(b, d); }
ll calc4(ll b, ll d) { return (d - b) * 2ll - calc2(b, d); }
int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll width = c - a;
  ll rep = width / 4ll;
  vector<ll> typ(4, 0);
  for (ll cur = a; cur + rep * 4ll < c; cur++) {
    typ[(cur % 4ll + 4ll) % 4ll]++;
  }
  dbg(rep);
  dbg(typ);
  ll res = 0;
  res += calc1(b, d) * (rep + typ[0]);
  res += calc2(b, d) * (rep + typ[1]);
  res += calc3(b, d) * (rep + typ[2]);
  res += calc4(b, d) * (rep + typ[3]);
  cout << res << endl;

  return 0;
}
