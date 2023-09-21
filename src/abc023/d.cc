#include <algorithm>
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
  vector<ll> hv(n), sv(n);
  rep(i, n) cin >> hv[i] >> sv[i];

  ll ub = 100000000000000ll, lb = *max_element(begin(hv), end(hv)) - 1ll;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2ll;
    bool ok = true;
    vector<ll> times;
    rep(i, n) {
      ll time = (mid - hv[i]) / sv[i];
      times.push_back(time);
    }
    dbg(mid, times);
    sort(begin(times), end(times));

    int a = 0;
    for (auto time : times) {
      if (time < a)
        ok = false;
      else
        a++;
    }
    dbg(ok);
    if (ok)
      ub = mid;
    else
      lb = mid;
  }
  cout << ub << endl;
  return 0;
}
