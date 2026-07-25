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
  int t;
  cin >> t;
  rep(_, t) {
    int n;
    cin >> n;
    vector<ll> sv(n - 2);
    ll cur, goal;
    cin >> cur;
    rep(i, n - 2) cin >> sv[i];
    sort(sv.begin(), sv.end());
    cin >> goal;

    int res = 2;
    dbg(sv);
    for (int i = 0; i < n - 2;) {
      if (2ll * cur >= goal)
        break;
      else if (i < n - 3 && 2ll * cur >= sv[i + 1]) {
        i++;
        continue;
      } else if (cur * 2ll >= sv[i]) {
        cur = sv[i];
        dbg(cur);
        res++;
        i++;
        continue;
      } else
        break;
    }
    if (2ll * cur >= goal) {
      cout << res << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
