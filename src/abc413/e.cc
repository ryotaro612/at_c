#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
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
ll my_pow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1)
      res *= x;
    n >>= 1;
    x *= x;
  }
  return res;
}

void solve(vector<ll> &pv, int l, int r) {

  if (r - l <= 1) {
    return;
  }
  solve(pv, l, (l + r) / 2);
  solve(pv, (l + r) / 2, r);
  if (pv[l] > pv[(l + r) / 2]) {

    vector<ll> temp(pv.begin() + l, pv.begin() + (l + r) / 2);
    rep(i, (r - l) / 2) { pv[l + i] = pv[(l + r) / 2 + i]; }
    rep(i, (r - l) / 2) { pv[(l + r) / 2 + i] = temp[i]; }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;

  rep(_, t) {
    int n;
    cin >> n;
    vector<ll> pv;
    rep(i, pow(2, n)) {
      ll p;
      cin >> p;
      pv.push_back(p);
    }
    solve(pv, 0, pv.size());
    rep(i, pv.size()) { cout << pv[i] << " \n"[i == pv.size() - 1]; }
  }

  return 0;
}
