#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
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
  ll n, k;
  cin >> n >> k;
  vector<ll> av(n), bv(n), cv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  rep(i, n) cin >> cv[i];
  sort(av.begin(), av.end());
  sort(bv.begin(), bv.end());
  sort(cv.begin(), cv.end());

  ll ub = av[n - 1] * bv[n - 1] + bv[n - 1] * cv[n - 1] +
          av[n - 1] * cv[n - 1] + 1ll,
     lb = 0;

  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2ll;
    ll count = 0;
    for (int ai = n - 1; ai >= 0; ai--) {
      for (int bi = n - 1; bi >= 0; bi--) {

        ll sub_lb = -1, sub_ub = n;
        while (sub_ub - sub_lb > 1ll) {
          int sub_mid = (sub_lb + sub_ub) / 2ll;
          if (mid - av[ai] * bv[bi] <= (av[ai] + bv[bi]) * cv[sub_mid]) {
            sub_ub = sub_mid;
          } else {
            sub_lb = sub_mid;
          }
        }
        dbg(mid, ai, bi, n - sub_ub, count);
        count += (ll)n - sub_ub;

        if (k <= count || n == sub_ub) {
          break;
        }
      }
      if (k <= count) {
        break;
      }
    }
    if (k <= count) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  cout << lb << endl;

  return 0;
}
