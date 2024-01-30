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
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];

  priority_queue<pair<ll, int>> que;
  rep(i, n) {
    if (bv[i] > av[i]) {
      if (bv[i] > bv[(i + 1) % n] + bv[(i - 1 + n) % n]) {
        que.push({bv[i], i});
      }
    }
  }
  ll res = 0;
  while (que.size()) {
    auto [cost, i] = que.top();
    que.pop();
    if (bv[i] != cost || bv[i] == av[i])
      continue;

    ll step = bv[(i + 1) % n] + bv[(i - 1 + n) % n];
    ll count = (bv[i] - av[i]) / step;
    if (count == 0) {
      cout << -1 << endl;
      return 0;
    }
    res += count;
    bv[i] -= count * step;

    if (bv[i] != av[i] && bv[i] > step)
      que.push({bv[i], i});
    if (bv[(i + 1) % n] != av[(i + 1) % n] &&
        bv[(i + 1) % n] > bv[i] + bv[(i + 2) % n])
      que.push({bv[(i + 1) % n], (i + 1) % n});
    if (bv[(i - 1 + n) % n] != av[(i - 1 + n) % n] &&
        bv[(i - 1 + n) % n] > bv[i] + bv[(i - 2 + n) % n])
      que.push({bv[(i - 1 + n) % n], (i - 1 + n) % n});
  }
  dbg(bv);
  rep(i, n) {
    if (av[i] != bv[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << res << endl;
  return 0;
}
