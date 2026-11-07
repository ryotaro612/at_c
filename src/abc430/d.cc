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

  map<ll, ll> pos;
  pos[0] = 0;

  ll x;
  cin >> x;
  pos[0] = x;
  pos[x] = x;
  ll res = x + x;
  cout << res << endl;
  rep(_, n - 1) {
    cin >> x;
    auto iter = pos.lower_bound(x);
    ll pre = prev(iter)->first;
    pos[x] = x - pre;
    if (x - pre < pos[pre]) {
      res -= pos[pre];
      pos[pre] = x - pre;
      res += pos[pre];
    }
    if (iter != pos.end()) {
      ll post = iter->first;
      if (post - x < pos[post]) {
        res -= pos[post];
        pos[post] = post - x;
        res += pos[post];
      }
      if (post - x < pos[x]) {
        pos[x] = post - x;
      }
    }
    res += pos[x];
    cout << res << endl;
  }

  return 0;
}
