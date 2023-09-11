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
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<int> xv(m), cnt(n, 0);

  rep(i, m) {
    cin >> xv[i];
    cnt[--xv[i]]++;
  }
  vector<pair<int, int>> order(n);
  rep(i, n) order[i] = {cnt[i], i};
  sort(begin(order), end(order));
  int res = 0;
  for (auto &[freq, i] : order) {
    if (freq == 0)
      res++;
    else if (freq <= b) {
      res++;
      b -= freq;
      a -= freq;
    } else if (a == b) {
      res++;
    } else
      a--;
  }
  cout << res << endl;
  return 0;
}
