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
  int n, m, l;
  cin >> n >> m >> l;
  vector<ll> av(n), bv(m);
  rep(i, n) { cin >> av[i]; }
  rep(i, m) { cin >> bv[i]; }
  ll res = 0;
  vector<vector<ll>> ng(n);
  rep(_, l) {
    ll c, d;
    cin >> c >> d;
    ng[--c].push_back(bv[--d]);
  }
  sort(begin(bv), end(bv), greater<ll>());
  rep(i, n) {
    if ((int)ng[i].size() == m)
      continue;
    sort(begin(ng[i]), end(ng[i]), greater<ll>());
    int lb = -1, ub = m;
    dbg(ng[i]);
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      dbg(mid);
      if (mid < (int)ng[i].size() &&  bv[mid] == ng[i][mid])
        lb = mid;
      else
        ub = mid;
    }
    res = max(res, av[i] + bv[ub]);
  }
  
  cout << res << endl;
  return 0;
}
