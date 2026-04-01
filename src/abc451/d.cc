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
  ll n;
  cin >> n;

  vector<ll> base = {1};
  ll offset = 1000000000ll;
  while (true) {
    auto v = base.back();
    if (v * 2ll <= offset) {
      base.push_back(v * 2ll);
    } else {
      break;
    }
  }
  dbg(base);
  map<int, set<ll>> mp;
  for (auto e : base) {
    mp[to_string(e).size()].insert(e);
  }
  set<ll> res;
  rep(i, 10) {
    dbg(i, mp[i].size());
    for (auto e : mp[i]) {
      res.insert(e);
      if (i == 9)
        continue;
      for (auto b : base) {
        auto nv = to_string(b) + to_string(e);
        if (nv.size() <= 9 && stoll(nv) <= offset) {
          mp[nv.size()].insert(stoll(nv));
        }
      }
    }
  }
  vector<ll> ans(res.begin(), res.end());

  cout << ans[n - 1] << endl;

  return 0;
}
