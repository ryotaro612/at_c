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
  int n, k;
  cin >> n >> k;
  vector<int> av(k);
  rep(i, k) cin >> av[i];
  int res = 0;
  if (k == 1) {
    res = 0;
  } else if (k % 2) {
    int right = 0;
    for (int i = k - 2; i >= 0; i -= 2) {
      right += av[i + 1] - av[i];
    }
    res = right;
    int left = 0;
    for (int i = 2; i <= k - 1; i += 2) {
      left += av[i - 1] - av[i - 2];
      right -= av[i] - av[i - 1];
      res = min(left + right, res);
    }

  } else {
    for (int i = 0; i < k; i += 2) {
      res += av[i + 1] - av[i];
    }
  }
  cout << res << endl;
  return 0;
}
