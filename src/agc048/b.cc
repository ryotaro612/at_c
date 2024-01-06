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
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  vector<pair<ll, int>> odd, even;
  for (int i = 0; i < n; i += 2) {
    even.push_back({bv[i] - av[i], i});
  }
  for (int i = 1; i < n; i += 2) {
    odd.push_back({bv[i] - av[i], i});
  }

  sort(begin(even), end(even));
  sort(begin(odd), end(odd));
  dbg(even.size(), odd.size());
  ll temp = 0;
  for (int i = 0; i < n / 2; i++) {
    dbg(i);
    int even_i = even[i].second;
    int odd_i = odd[i].second;
    dbg(i, "doge");
    temp += av[even_i] + av[odd_i];
  }
  dbg("doge");  
  ll res = temp;
  ll rest = 0;
  for (int i = n / 2 - 1; i >= 0; i--) {
    int even_i = even[i].second;
    int odd_i = odd[i].second;
    temp -= av[even_i] + av[odd_i];
    rest += bv[even_i] + bv[odd_i];
    res = max(res, temp + rest);
  }
  cout << res << endl;
  return 0;
}
