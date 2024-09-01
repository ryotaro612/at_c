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
  vector<int> av(n);
  vector<char> sv(n);
  rep(i, n) cin >> av[i] >> sv[i];
  int pos_l, pos_r;
  for (int i = n - 1; i >= 0; i--) {
    if (sv[i] == 'L')
      pos_l = av[i];
    else
      pos_r = av[i];
  }
  int res = 0;
  rep(i, n) {
    if (sv[i] == 'L') {
      res += abs(av[i] - pos_l);
      pos_l = av[i];
    } else {
      res += abs(av[i] - pos_r);
      pos_r = av[i];
    }
  }
  cout << res << endl;

  return 0;
}
