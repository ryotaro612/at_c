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
  vector<ll> hv(n);
  rep(i, n) cin >> hv[i];
  vector<pair<ll, ll>> heights = {{1ll << 60ll, 0}};
  ll time = 0;
  vector<ll> res;
  for (ll i = 0; i < n; i++) {
    dbg(i);
    while (heights.back().first < hv[i]) {
	  int size = heights.size();
	  time += (hv[i] - heights[size-1].first) * (heights[size-1].second - heights[size-2].second);
	  heights.pop_back();
    }
    time += hv[i];
    dbg(time);
    res.push_back(time + 1ll);

    heights.push_back({hv[i], i + 1ll});
  }
  rep(i, res.size()){
	cout << res[i] << " \n"[res.size() - 1 == i];
  }
  return 0;
}
