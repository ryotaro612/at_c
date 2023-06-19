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
  int n;
  cin >> n;
  vector<ll> tv(n), av(n), lb(n, 10000000000ll), ub(n, -10000000000ll);
  rep(i, n) cin >> tv[i];
  rep(i, n) cin >> av[i];
  lb[0] = ub[0] = tv[0];
  for (int i = 1; i < n; i++) {
    if (tv[i - 1] == tv[i]) {
      ub[i] = ub[i - 1];
      lb[i] = 1ll;
    } else {
      ub[i] = lb[i] = tv[i];
    }
  }
  if (!(lb[n - 1] <= av[n - 1] && av[n - 1] <= ub[n - 1])) {
    cout << 0 << endl;
    return 0;
  }
  lb[n - 1] = ub[n - 1] = av[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (av[i] == av[i + 1]) {
      // [0, av[i+1]]
      ub[i] = min(ub[i], av[i + 1]);
    } else {
      // h[i] = av[i]
      if (lb[i] <= av[i] && av[i] <= ub[i]) {
        lb[i] = ub[i] = av[i];
      } else {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  debug(lb);
  debug(ub);

  ll mod = 1000000007ll, res = 1ll;
  rep(i, n) {
    ll temp = ub[i] - lb[i];
    if (temp < 0)
      temp += mod;
    temp += 1ll;
    temp %= mod;
    res *= temp;
    res %= mod;
  }
  cout << res << endl;
  return 0;
}
#endif
