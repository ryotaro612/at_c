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
  ll a, b;
  cin >> n >> a >> b;
  set<ll> ds;
  rep(i, n) {
    ll d;
    cin >> d;
    ds.insert(d % (a + b));
  }
  vector<ll> dv(begin(ds), end(ds));
  dv.push_back(dv[0] + (a + b));
  dbg(dv);
  for (int i = 1; i < (int)dv.size(); i++) {
    if (dv[i] - dv[i - 1] > b) {
      cout << "Yes\n";
      return 0;
    }
  }
  /**/
  cout << "No\n";
  return 0;
}
