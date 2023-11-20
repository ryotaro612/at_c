#include <algorithm>
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
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  ll v = 0;
  for (auto a : av)
    v ^= a;
  if (v) {
    cout << -1 << endl;
    return 0;
  }
  map<ll, int> freq;
  for (auto e : av)
    freq[e]++;
  bool ok = false;
  ll mx = 0;
  for (auto [a, f] : freq) {
    if (f % 2ll) {
      ok = true;
      mx = max(mx, a);
    }
  }
  if(ok) {
    cout << mx - 1ll << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
