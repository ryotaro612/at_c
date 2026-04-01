#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
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
  int n, k;
  cin >> n >> k;
  ll mx = -1;
  vector<ll> av(n);
  rep(i, n) {
    cin >> av[i];
    mx = max(mx, av[i]);
  }

  rep(i, n) {
    ll diff = mx - av[i];
    av[i] += diff / k * k;
  }

  ll mini = *min_element(av.begin(), av.end());
  ll res = mx - mini;
  dbg(av);
  dbg(res);
  multiset<ll> st(av.begin(), av.end());
  rep(i, n) {
    ll v = *st.begin();
    st.erase(st.begin());
    st.insert(v + k);
    res = min(res, *st.rbegin() - *st.begin());
  }

  cout << res << endl;

  return 0;
}
