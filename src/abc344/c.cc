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
  int n, m, l, q;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cin >> m;
  vector<ll> bv(m);
  rep(i, m) cin >> bv[i];
  cin >> l;
  vector<ll> cv(l);
  rep(i, l) cin >> cv[i];
  cin >> q;
  set<ll> cands;
  for (auto a : av) {
    for (auto b : bv) {
      for (auto c : cv) {
        cands.insert(a + b + c);
      }
    }
  }
  rep(i, q) {
    ll x;
    cin >> x;
    if (cands.find(x) == cands.end()) {
      cout << "No\n";
    } else
      cout << "Yes\n";
  }

  return 0;
}
