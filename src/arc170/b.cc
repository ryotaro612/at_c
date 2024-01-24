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
  ll n;
  cin >> n;
  vector<int> av(n);
  vector<vector<int>> vals(11);
  rep(i, n) {
    cin >> av[i];
    vals[av[i]].push_back(i);
  }
  vector<pair<int, int>> pos;
  rep(i, n) {
    int bound = n;
    for (int diff = -10; diff <= 10; diff++) {
      if (!(1 <= diff * 2 + av[i] && diff * 2 + av[i] <= 10))
        continue;
      auto mid =
          upper_bound(begin(vals[av[i] + diff]), end(vals[av[i] + diff]), i);
      if (mid == end(vals[av[i] + diff]))
        continue;
      auto right = upper_bound(begin(vals[av[i] + diff * 2]),
                               end(vals[av[i] + diff * 2]), *mid);
      if (right == end(vals[av[i] + diff * 2]))
        continue;
      bound = min(bound, *right);
    }
    if (bound < n) {
      while (pos.size() && bound <= pos.back().second)
        pos.pop_back();
      pos.push_back({i, bound});
    }
  }

  dbg(pos);
  reverse(begin(pos), end(pos));
  ll res = 0;
  rep(i, n) {
    if (pos.size()) {
      res += pos.back().second - i - 1;
      if (pos.back().first == i)
        pos.pop_back();
    } else {
      res += n - 1 - i;
    }
  }
  res = n * (n - 1ll) / 2ll - res;
  cout << res << endl;
  return 0;
}
