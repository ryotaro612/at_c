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
ll solve(int i, ll left, ll right, vector<ll> &lv, vector<ll> &rv,
         vector<ll> &res) {
  int n = lv.size();
  if (i == n - 1) {
    ll a = max(lv[i], left);
    res.push_back(a);
    return a;
  }
  ll tail = solve(i + 1, left - rv[i], right - lv[i], lv, rv, res);
  ll a = left - tail;
  ll b = right - tail;
  ll cand = max(a, lv[i]);
  res.push_back(cand);
  return tail + cand;
}
int main() {
  int n;
  cin >> n;
  vector<ll> lv(n), rv(n);
  rep(i, n) { cin >> lv[i] >> rv[i]; }

  ll mini = lv[0], maxi = rv[0];
  for (int i = 1; i < n; i++) {
    mini += lv[i];
    maxi += rv[i];
  }
  if (!(mini <= 0 && 0 <= maxi)) {
    cout << "No\n";
    return 0;
  }
  vector<ll> res;
  solve(0, 0, 0, lv, rv, res);
  reverse(begin(res), end(res));
  ll acc = 0;
  rep(i, n) acc += res[i];
  assert(acc == 0);
  cout << "Yes\n";
  rep(i, n) { cout << res[i] << " \n"[i == n - 1]; }
  return 0;
}
