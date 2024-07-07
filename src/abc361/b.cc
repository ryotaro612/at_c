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

bool mid(int a, int b, int c, int d) { return !(b <= c || d <= a); }

int main() {
  vector<int> av(6), bv(6);
  rep(i, 6) cin >> av[i];
  rep(i, 6) cin >> bv[i];
  bool ok = false;
  if (mid(av[0], av[3], bv[0], bv[3]) && mid(av[1], av[4], bv[1], bv[4]) &&
      mid(av[2], av[5], bv[2], bv[5]))
    ok = true;

  if (ok) {
    cout << "Yes\n";
  } else
    cout << "No\n";
  return 0;
}
