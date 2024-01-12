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
bool solve(vector<int> &av) {
  int n = av.size();
  int odd_even = 0;
  rep(i, n) {
    // n-1 c i
    if (((n - 1) & i) == i) {
      odd_even ^= av[i];
    }
  }
  return odd_even & 1;
}
int main() {
  int n;
  cin >> n;
  string as;
  cin >> as;
  vector<int> av(n);
  bool one = false;
  rep(i, n) {
    av[i] = as[i] - '0' - 1;
    if (av[i] == 1)
      one = true;
  }
  if (solve(av)) {
    cout << 1 << endl;
    return 0;
  }
  if (one) {
    cout << 0 << endl;
    return 0;
  }
  rep(i, n) { av[i] /= 2; }
  if (solve(av)) {
    cout << 2 << endl;
  } else
    cout << 0 << endl;

  return 0;
}
