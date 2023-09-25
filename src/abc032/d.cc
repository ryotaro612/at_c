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

void sub(vector<pair<ll, ll>> &vwv, ll w, ll &best) {
  ll cur_w = 0, cur_v = 0;
  int i = 0, n = vwv.size();

  for (; i < n; i++) {
    if (cur_w + vwv[i].second <= w) {
      cur_v += vwv[i].first;
      cur_w += vwv[i].second;
    } else
      break;
  }
  if (cur_w == w || i == n) {
    best = max(best, cur_v);
    return;
  }
  if ((ld)cur_v + (ld)(w - cur_w) * (ld)vwv[i].first / (ld)vwv[i].second <
      (ld)best)
    return;

  vector<pair<ll, ll>> vwv_sub;
  rep(j, n) {
    if (i != j)
      vwv_sub.push_back(vwv[j]);
  }
  // 使うパターン
  if (vwv[i].second <= w) {
    ll sub_v = best - vwv[i].first;
    sub(vwv_sub, w - vwv[i].second, sub_v);
    best = max(best, sub_v + vwv[i].first);
  }
  sub(vwv_sub, w, best);
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<pair<ll, ll>> vwv(n);
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    vwv[i] = {a, b};
  }
  sort(begin(vwv), end(vwv), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return (ld)a.first / (ld)a.second > (ld)b.first / (ld)b.second;
  });
  ll res = 0;
  sub(vwv, w, res);
  cout << res << endl;
  return 0;
}
