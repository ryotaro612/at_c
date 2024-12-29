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
ll res = 0;
void solve(int i, int k, vector<ll> &av, ll temp) {
  if (i == (int)av.size()) {
    if (k == 0) {
      res = max(res, temp);
      return;
    }
    return;
  }
  if (k == 0) {
    res = max(res, temp);
    return;
  }
  solve(i + 1, k, av, temp);
  solve(i + 1, k - 1, av, temp ^ av[i]);
}
ll mask = 0;
void solve2(int i, int k, vector<ll> &av, ll temp) {
  if (i == (int)av.size()) {
    if (k == 0) {
      res = max(res, mask ^ temp);
      return;
    }
    return;
  }
  if (k == 0) {
    res = max(res, mask ^ temp);
    return;
  }
  solve2(i + 1, k, av, temp);
  solve2(i + 1, k - 1, av, temp ^ av[i]);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  if (k <= n - k) {
    ll temp = 0;
    solve(0, k, av, temp);
    cout << res << endl;
	return 0;
  }
  rep(i, n) mask ^= av[i];
  solve2(0, n-k, av, 0);
  cout << res << endl;
  return 0;
}
