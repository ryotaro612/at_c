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
  ll n, d;
  cin >> n >> d;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  int right = 0;
  multiset<ll> st;
  st.insert(-10e15);
  st.insert(10e15);
  ll res = 0;
  rep(left, n) {
    right = max(left, right);

    while (right < n) {
      auto it = st.lower_bound(av[right]);
      if (it != st.end() && *it - av[right] < d)
        break;
      if (it != st.begin() && av[right] - *prev(it) < d)
        break;
      st.insert(av[right]);
      right++;
    }
    dbg("hi");
    res += (ll)(right - left);

    st.erase(st.find(av[left]));
  }
  cout << res << endl;
  return 0;
}
