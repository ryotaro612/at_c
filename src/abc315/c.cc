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
  vector<vector<ll>> mp(n + 1);
  vector<pair<ll, ll>> fs(n);
  rep(i, n) {
    ll f, s;
    cin >> f >> s;
    fs[i] = {s, f};
    mp[f].push_back(s);
  }
  ll res = 0ll;
  for(vector<ll> &v: mp) {
    sort(begin(v), end(v));
    if(size(v) > 1) {
      res = max(res, v[size(v) - 1] + v[size(v) - 2] / 2ll);
    }
  }
  sort(begin(fs), end(fs));
  int color = fs[size(fs)-1].second;
  ll temp = fs[size(fs) -1].first;
  for(int i = size(fs) - 2;i>=0;i--) {
    if(fs[i].second != color) {
      res = max(res, fs[i].first + temp);
    }
  }
  cout << res << endl;  
  return 0;
}
