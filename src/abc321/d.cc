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
  int n, m;
  ll p;
  cin >> n >> m >> p;
  vector<ll> av(n), bv(m);
  rep(i, n) cin >> av[i];
  rep(i, m) cin >> bv[i];
  ll res = 0;
  sort(begin(bv), end(bv));
  vector<ll> sum(m + 1, 0);
  rep(i, m) sum[i + 1] = bv[i] + sum[i];

  rep(i, n) {
    int lb = -1, ub = m;
    while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (av[i] + bv[mid] < p)
        lb = mid;
      else
        ub = mid;
    }
    res += av[i] * (lb + 1ll) + sum[lb + 1];
    res += p * (m - (lb + 1));
  }
  cout << res << endl;
  return 0;
}
