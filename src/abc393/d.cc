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

ll calc(vector<ll> &v, ll pivot) {
  ll res = 0;
  ll dest = v[pivot] - 1ll;
  for (ll i = pivot - 1; i >= 0; i--) {
    res += abs(dest - v[i]);
    dest--;
  }
  dest = v[pivot] + 1;
  for (ll i = pivot + 1ll; i < (ll)v.size(); i++) {
    res += abs(dest - v[i]);
    dest++;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> pos;
  rep(i, n) {
    if (s[i] == '1')
      pos.emplace_back(i);
  }
  int pivot = pos.size() / 2;
  ll res = calc(pos, pivot);
  if (pos.size() % 2 == 0) {
    res = min(res, calc(pos, pivot - 1));
  }
  cout << res << endl;
  return 0;
}
