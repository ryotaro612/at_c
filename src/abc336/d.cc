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
  rep(i, n) cin >> av[i];
  vector<ll> left(n), right(n);
  left[0] = 1;
  right[n - 1] = 1;
  ll res = 0;
  for (int i = 1; i < n; i++) {
    left[i] = min(left[i - 1] + 1ll, av[i]);
    right[n - 1 - i] = min(right[n - 1 - i + 1] + 1ll, av[n - 1 - i]);
  }
  rep(i, n) {
    res = max(res, min(left[i], right[i]));
  }
  cout << res << endl;
  return 0;
}
