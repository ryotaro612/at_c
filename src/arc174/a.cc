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
  ll n, c;
  cin >> n >> c;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];

  vector<ll> prefix(n + 1, 0), mx(n + 1, -1e17), mn(n + 1, 1e15);
  vector<int> mx_pos(n + 1), mn_pos(n + 1);
  rep(i, n) { prefix[i + 1] = prefix[i] + av[i]; }
  mx[n] = mn[n] = prefix[n];
  mx_pos[n] = mn_pos[n] = n;
  for (int i = n - 1; i >= 0; i--) {
    if (mx[i + 1] <= prefix[i]) {
      mx[i] = prefix[i];
      mx_pos[i] = i;
    } else {
      mx[i] = mx[i + 1];
      mx_pos[i] = mx_pos[i + 1];
    }

    if (prefix[i] <= mn[i + 1]) {
      mn[i] = prefix[i];
      mn_pos[i] = i;
    } else {
      mn[i] = mn[i + 1];
      mn_pos[i] = mn_pos[i + 1];
    }
  }
  dbg("hi");
  ll res = prefix[n];
  dbg(prefix);
  dbg(mx);
  dbg(mx_pos);
  dbg(mn);
  dbg(mn_pos);
  rep(i, n) {
    ll cand = prefix[n];
    cand -= prefix[mx_pos[i]] - prefix[i];
    cand += (prefix[mx_pos[i]] - prefix[i]) * c;
    res = max(res, cand);

    cand = prefix[n];
    cand -= prefix[mn_pos[i]] - prefix[i];
    cand += (prefix[mn_pos[i]] - prefix[i]) * c;
    res = max(res, cand);
  }

  cout << res << endl;
  return 0;
}
