#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n+1, 0);
  ll right = 0, res = 0, left = 0, left_black = 0;
  rep(i, n) {
    cin >> av[i];
    right += av[i];
  }
  left = av[0];
  right -= av[0] + av[1];

  for (int i = 1; i < n; i += 2) {
    ll l_cand = 2ll * (left + left_black * 2ll) + av[i] + 1ll;
    ll r_cand = 2ll * (right + (n / 2ll - left_black - 1ll) * 2ll) + av[i] + 1ll;
    debug(i, l_cand, r_cand);
    res += min(l_cand, r_cand);
    left += av[i] + av[i+1];
    right -= av[i+1] + av[i+2];
    left_black++;
  }
  cout << res << endl;
  return 0;
}
#endif
