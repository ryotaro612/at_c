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
  mt19937 rand_src(12345);
  // auto  = rand_src();
  int n, q;
  cin >> n >> q;
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  map<int, ll> mp;
  vector<ll> prefix_a(n + 1, 0), prefix_b(n + 1, 0);
  rep(i, n) {
    if (!mp.count(av[i]))
      mp[av[i]] = rand_src();
    prefix_a[i + 1] = prefix_a[i] + mp[av[i]];

    if (!mp.count(bv[i]))
      mp[bv[i]] = rand_src();
    prefix_b[i + 1] = prefix_b[i] + mp[bv[i]];
  }
  rep(i, q) {
    int al, ar, bl, br;
    cin >> al >> ar >> bl >> br;
    al--;
    ar--;
    bl--;
    br--;
    if (prefix_a[ar + 1] - prefix_a[al] == (prefix_b[br + 1] - prefix_b[bl])) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
