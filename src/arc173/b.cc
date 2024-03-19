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
  vector<ll> xv(n), yv(n);
  map<tuple<__int128, __int128, __int128>, set<int>> freq;
  rep(i, n) { cin >> xv[i] >> yv[i]; }
  // for (int i = 0; i < n; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     __int128 a = (__int128)yv[j] - (__int128)yv[i];
  //     __int128 b = (__int128)xv[i] - (__int128)xv[j];
  //     __int128 c = (__int128)(-xv[i]) * (__int128)yv[j] +
  //                  (__int128)yv[i] * (__int128)xv[j];
  //     if (a < 0) {
  //       a *= (__int128)(-1ll);
  //       b *= (__int128)(-1ll);
  //       c *= (__int128)(-1ll);
  //     } else if (a == 0 && b < 0) {
  //       b *= (__int128)(-1ll);
  //       c *= (__int128)(-1ll);
  //     }
  //     freq[{a, b, c}].insert(i);
  //     freq[{a, b, c}].insert(j);
  //   }
  // }

  // for (auto &[k, s] : freq) {
  //   int f = size(s);
  //   if (n - n / 3 + 1 <= f) {
  //     cout << n - f << endl;
  //     return 0;
  //   }
  // }
  cout << n / 3 << endl;
  return 0;
}

