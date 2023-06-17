#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  os << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) os << v[i] << s[i == int(v.size()) - 1];
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<S, T> a) {
  os << "{" << a.first << ", " << a.second << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, set<T> &v) {
  os << "{";
  string s[2] = {", ", "}"};
  int size = v.size(), i = 0;
  for (auto e : v) {
    os << e << s[i == (size - 1)];
    i++;
  }
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

#ifdef ONLINE_JUDGE
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<ll> yv(n, 0ll);
  set<pair<ll, int>> large, small;
  rep(i, n) {
    if (i < k) {
      large.insert({0, i});
    } else {
      small.insert({0, i});
    }
  }
  ll res = 0ll;
  rep(i, q) {
    // debug("i", i);
    ll x, y;
    cin >> x >> y;
    if (large.count({yv[--x], x})) {
      res -= yv[x];
      large.erase({yv[x], x});
      yv[x] = y;
      res += y;
      large.insert({yv[x], x});
      // debug(yv[x]);
    } else {
      small.erase({yv[x], x});
      yv[x] = y;
      small.insert({yv[x], x});
    }
    while (k <= int(large.size())) {
      pair<ll, int> p = *large.begin();
      large.erase(p);
      res -= p.first;
      small.insert(p);
    }
    pair<ll, int> p = *prev(small.end());
    small.erase(p);
    res += p.first;
    large.insert(p);
    debug("small:", small, "large:", large);
    cout << res << endl;
  }
  return 0;
}
#endif
