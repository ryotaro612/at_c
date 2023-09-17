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
  vector<ll> somen(n, 0);
  set<int> wait;
  rep(i, n) wait.insert(i);
  set<pair<ll, int>> left;
  rep(_, m) {
    ll t, s, w;
    cin >> t >> w >> s;
    while (left.size()) {
      auto iter = begin(left);
      if (iter->first <= t) {
        wait.insert(iter->second);
        left.erase(iter);
      } else
        break;
    }
    if (wait.size()) {
      auto iter = begin(wait);
      somen[*iter] += w;
      left.insert({t + s, *iter});
      wait.erase(iter);      
    }
  }
  rep(i, n) cout << somen[i] << endl;
  return 0;
}
