#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
  return os;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  if (v.size() == 0) {
    os << "]";
    return os;
  }
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}

void debug_() { cout << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

// #ifdef ONLINE_JUDGE
int main() {
  int n, gt = 0;
  cin >> n;
  vector<ll> av(n), bv(n);
  rep(i, n) {
    cin >> av[i] >> bv[i];
    if (av[i] > bv[i])
      gt++;
  }
  ll res = 0ll;
  rep(i, n) res += max(av[i], bv[i]);
  if (gt % 2) {
    ll mini = numeric_limits<ll>::max();
    rep(i, n) { mini = min(mini, abs(av[i] - bv[i])); }
    res -= mini;
  }
  cout << res << endl;

  return 0;
}
// #endif
