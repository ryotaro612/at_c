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

ll count(vector<ll> v) {
  ll res = 0ll;
  rep(i, v.size()) {
    res += v[i] / 2ll;
    v[i] %= 2ll;
    if (i < int(v.size()) - 1) {
      ll delta = min(v[i], v[i + 1]);
      v[i] -= delta;
      v[i + 1] -= delta;
      res += delta;
    }
  }
  return res;
}

// #ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll res = 0ll;
  vector<ll> buf;
  rep(i, n) {
    if (av[i])
      buf.push_back(av[i]);

    if (av[i] == 0 || i == n - 1) {
      ll temp = count(buf);
      reverse(begin(buf), end(buf));
      temp = max(temp, count(buf));
      res += temp;

      buf.clear();
    }
  }
  cout << res << endl;
  return 0;
}
// #endif
