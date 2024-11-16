#include <bits/stdc++.h>
#include <limits>
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
  int t;
  cin >> t;
  rep(_, t) {
    int n, k;
    cin >> n >> k;
    vector<ll> av(n), bv(n);
    rep(i, n) cin >> av[i];
    rep(i, n) cin >> bv[i];
    vector<pair<ll, ll>> pv(n);
    rep(i, n) { pv[i] = {av[i], bv[i]}; }
    sort(begin(pv), end(pv));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        que;
    rep(i, n - 1) { que.push({pv[i].second, i}); }
    set<int> bag;
    ll sum = 0;
    rep(i, k - 1) {
      auto [b, idx] = que.top();
      que.pop();
      sum += b;
      bag.insert(idx);
    }
    ll res = numeric_limits<ll>::max();
    for (int i = n - 1; i >= 0; i--) {
      if (bag.contains(i)) {
        sum -= pv[i].second;
        bag.erase(i);
        while (que.size() && que.top().second >= i)
          que.pop();
        if (que.size() == 0)
          break;
        auto [b, idx] = que.top();
        que.pop();
        sum += b;
        bag.insert(idx);
      }
      if (bag.size() == k - 1) {
        ll cand = pv[i].first * (pv[i].second + sum);
        res = min(cand, res);
      }
    }

    cout << res << endl;
  }
  return 0;
}
