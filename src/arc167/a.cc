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
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  sort(begin(av), end(av));
  dbg(av);
  vector<ll> bv(m, 0);
  rep(i, m) {
    if (av.size()) {
      bv[i] = av.back();
      av.pop_back();
    }
  }
  reverse(begin(bv), end(bv));
  dbg(bv);
  dbg(av);
  rep(i, m) {
    if (av.size()) {
      bv[i] += av.back();
      av.pop_back();
    } else
      break;
  }
  ll res = 0;
  dbg(bv);
  rep(i, m) { res += bv[i] * bv[i]; }
  cout << res << endl;
  return 0;
}
