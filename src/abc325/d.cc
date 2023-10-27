#include <bits/stdc++.h>
#include <system_error>
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
  multiset<pair<ll, ll>> start_end;
  rep(i, n) {
    ll t, d;
    cin >> t >> d;
    start_end.insert({t, t + d});
  }
  ll current = 0;
  int res = 0;
  multiset<pair<ll, ll>> available;
  while (true) {
    while (size(start_end) && begin(start_end)->first <= current) {
      auto item = *begin(start_end);
      available.insert({item.second, item.first});
      start_end.erase(begin(start_end));
    }

    while (available.size() && !(begin(available)->second <= current &&
                                 current <= begin(available)->first)) {
      available.erase(begin(available));
    }
    if(available.size()) {
      res++;
      available.erase(begin(available));
      current++;
    } else if(start_end.size()) {
      current = start_end.begin()->first;
      
    } else
      break;
  }
  cout << res << "\n";

  return 0;
}
