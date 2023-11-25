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

ll calc_grundy(ll n, ll l, ll r, vector<ll> &cache) {
  if (cache[n] != -1)
    return cache[n];
  if (n == 0)
    return cache[n] == 0;

  unordered_set<ll> st;
  for (ll i = l; i <= r && 0 <= n - i; i++) {
    st.insert(calc_grundy(n - i, l, r, cache));
  }
  ll res = 0;
  while (st.contains(res))
    res++;
  return cache[n] = res;
}

ll calc(ll n, ll l, ll r) {
  ll cnt = r / l;
  ll cycle = l * (cnt + 1ll) + r % l;
  n %= cycle;

  return n / l;
}
int main() {
  ll n, l, r, res = 0;
  cin >> n >> l >> r;
  rep(i, n) {
    ll a;
    cin >> a;
    //dbg(a, calc(n, l, r));
    res ^= calc(a, l, r);
  }
  if (res)
    cout << "First";
  else
    cout << "Second";
  cout << endl;
  return 0;

  vector<ll> cache(101, -1);
  rep(i, 101) {;
    ll v = calc_grundy(i, l, r, cache);
    dbg(i, v, calc(i, l, r));
  }

  return 0;
}
