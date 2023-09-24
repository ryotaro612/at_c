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
  int n, x;
  cin >> n >> x;
  vector<int> av(n - 1);
  rep(i, n - 1) cin >> av[i];
  sort(begin(av), end(av));
  int total = 0;
  for (int i = 0; i < n - 1; i++) {
    total += av[i];
  }
  if (total - av[n - 2] >= x) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = av[0]; i <= av[n - 2]; i++) {
    if (total - av[0] - av[n - 2] + i >= x) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
