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
ll forward(string &s, ll cur, ll sum, ll rest, ll m) {
  dbg(s, cur, sum, rest, m);
  ll n = s.size();
  if (cur == n * m)
    return cur;

  ll loop = rest / sum;
  if (loop) {
    return forward(s, cur + loop * n, sum, rest - loop * sum, m);
  } else {
    if (s[cur % n] == 'o') {
      return forward(s, cur + 1ll, sum, rest, m);
    } else {
      if (rest)
        return forward(s, cur + 1ll, sum, rest - 1ll, m);
      else
        return cur;
    }
  }
}

int main() {
  int n;
  ll m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  ll sum = 0;
  for (auto c : s)
    if (c == 'x')
      sum++;

  ll rest = k;
  ll right = forward(s, 0, sum, rest, m);
  ll res = right;
  dbg(0, right, right);
  for (ll i = 1ll; i < n; i++) {
    if (s[i - 1] == 'x') {
      right = forward(s, right, sum, 1ll, m);
    }
    dbg(i, right, right - i);
    res = max(res, right - i);
  }
  cout << res << endl;
  return 0;
}
