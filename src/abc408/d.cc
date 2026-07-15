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
    string s;
    cin >> n >> s;
    vector<ll> prefix(n + 1, 0);
    rep(i, n) { prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1 : 0); }
    vector<ll> right(n, 0);
    ll res = min(n - prefix[n], prefix[n]);
    for (int i = n - 1; i >= 0; i--) {
      // 黒にするコストi - prefix[i]
      // 白にするコストprefix[n] - prefix[i]
      right[i] = i - prefix[i] + (prefix[n] - prefix[i]);
      if (i == n - 1) {
        right[i] = min(right[i], n - prefix[n]);
      } else if (i < n - 1 && right[i + 1] < right[i]) {
        right[i] = right[i + 1];
      }
    }
    dbg(prefix);
    dbg(right);
    for (int i = 1; i < n; i++) {
      res = min(res, right[i] + prefix[i] - (i - prefix[i]));
    }
    res = min(res, right[0]);

    cout << res << endl;
  }
  return 0;
}
