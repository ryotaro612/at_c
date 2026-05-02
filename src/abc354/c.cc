#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
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
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> triplet(n);
  rep(i, n) {
    int a, c;
    cin >> a >> c;
    triplet[i] = {a, c, i};
  }
  sort(triplet.begin(), triplet.end());
  set<pair<ll, ll>> c_set;
  for (int i = 0; i < n; i++) {
    // c, i
    c_set.insert({get<1>(triplet[i]), get<2>(triplet[i])});
  }
  vector<int> res;
  for (auto [a, c, i] : triplet) {
    c_set.erase({c, i});
    if (c_set.size() && c_set.begin()->first < c) {
      continue;
    }
    res.push_back(i);
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  rep(i, res.size()) { cout << res[i] + 1 << " \n"[i == (int)res.size() - 1]; }

  return 0;
}
