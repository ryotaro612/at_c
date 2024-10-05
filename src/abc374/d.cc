#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <limits>
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

ld calc_time(ld from_x, ld to_x, ld from_y, ld to_y, ld speed) {
  ld dist = sqrt(abs(to_x - from_x) * abs(to_x - from_x) +
                 abs(to_y - from_y) * abs(to_y - from_y));
  return dist / speed;
}
int main() {
  int n;
  ld s, t;
  cin >> n >> s >> t;
  vector<ld> av(n), bv(n), cv(n), dv(n);
  rep(i, n) { cin >> av[i] >> bv[i] >> cv[i] >> dv[i]; }
  ld res = numeric_limits<ld>::max();
  vector<int> order(n);
  rep(i, n) { order[i] = i; }
  do {

    rep(mask, 1 << n) {
      ld cand = 0;
      ld x = 0, y = 0;
      dbg(order, mask);
      rep(i, n) {
        cand += calc_time(av[order[i]], cv[order[i]], bv[order[i]],
                          dv[order[i]], t);
        if (mask & (1 << i)) {
          cand += calc_time(x, av[order[i]], y, bv[order[i]], s);
          x = cv[order[i]];
          y = dv[order[i]];
        } else {
          cand += calc_time(x, cv[order[i]], y, dv[order[i]], s);
          x = av[order[i]];
          y = bv[order[i]];
        }
      }
      dbg(cand);
      res = min(cand, res);
    }

  } while (next_permutation(begin(order), end(order)));

  rep(i, n) {}
  cout << fixed << setprecision(12) << res << endl;

  return 0;
}
