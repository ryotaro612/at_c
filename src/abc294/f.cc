#include <bits/stdc++.h>
#include <iomanip>
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
  ll k;
  cin >> n >> m >> k;
  vector<double> av(n), bv(n), cv(m), dv(m);
  rep(i, n) cin >> av[i] >> bv[i];
  rep(i, m) cin >> cv[i] >> dv[i];
  double ub = 1, lb = 0;

  while (ub - lb > (double)0.000000000000001) {
    double mid = (ub + lb) / (double)2.0;
    vector<double> aoki(m);
    rep(i, m) { aoki[i] = cv[i] * mid - cv[i] + dv[i] * mid; }
    sort(begin(aoki), end(aoki));
    ll count = 0;
    //dbg(aoki);
    rep(i, n) {
      double takahashi = av[i] - av[i] * mid - bv[i] * mid;

      count += upper_bound(begin(aoki), end(aoki), takahashi) - begin(aoki);
      //dbg(takahashi, aoki, count);
    }
    dbg(mid, count);
    if (count < k) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  double res = ub * (double)100.0;
  cout << fixed << setprecision(16) << res<< endl;

  return 0;
}
