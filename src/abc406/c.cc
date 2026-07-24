
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> pv(n);
  rep(i, n) cin >> pv[i];

  ll res = 0;
  ll cond1 = -1, cond2 = -1;
  for (ll left = 0, right = 1; left < n - 3; left++) {

    if (pv[left] >= pv[left + 1])
      continue;

    right = max(left + 1, right);
    if (cond1 <= left)
      cond1 = -1;
    if (cond2 <= left)
      cond2 = -1;

    while (right < n - 1) { //  && (cond1 == -1 || cond2 == -1)
      if (pv[right - 1] < pv[right] && pv[right] > pv[right + 1]) {
        if (cond1 == -1) {
          cond1 = right;
        } else {
          break;
        }
      }
      if (pv[right - 1] > pv[right] && pv[right] < pv[right + 1]) {
        if (cond2 == -1) {
          cond2 = right;
        } else {
          break;
        }
      }
      right++;
    }

    if (cond1 == -1 || cond2 == -1)
      continue;

    ll inc = right - (max(cond1, cond2) + 1ll) + 1ll;
    dbg(left, right, cond1, cond2, inc);
    res += inc;
  }
  cout << res << endl;
  return 0;
}
