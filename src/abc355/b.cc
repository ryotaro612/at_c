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
  int n, m;
  cin >> n >> m;
  vector<int> av(n), bv(m);
  rep(i, n) { cin >> av[i]; }
  rep(i, m) cin >> bv[i];

  set<int> as(begin(av), end(av)), bs(begin(bv), end(bv));
  vector<int> cv;
  for (auto e : av)
    cv.push_back(e);
  for (auto e : bv)
    cv.push_back(e);
  sort(begin(cv), end(cv));
  rep(i, n + m - 1) {
    if (as.count(cv[i]) && as.count(cv[i + 1])) {
      cout << "Yes\n";
	  return 0;
    }
  }
  cout << "No\n";

  return 0;
}
