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
  int n, k;
  cin >> n >> k;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll mx = *max_element(av.begin(), av.end());
  vector<int> sv(mx + 1), tv(mx + 1), uv(mx + 1);
  rep(i, n) { sv[av[i]]++; }
  for (int i = 1; i <= mx; i++) {
    dbg(i);
    for (int j = i; j <= mx; j += i) {
      tv[i] += sv[j];
    }
  }

  rep(i, mx + 1) {
    if (tv[i] < k)
      continue;
    for (int j = i; j <= mx; j += i) {
      uv[j] = max(uv[j], i);
    }
  }

  rep(i, n) { cout << uv[av[i]] << endl; }

  return 0;
}
