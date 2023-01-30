#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <ostream>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

ll solve(ll a, ll b, set<ll> &points) {
  // for (auto c : points)
  //   cout << c << " ";
  // cout << endl;
  // 範囲内にあるか
  if (points.lower_bound(a) != points.lower_bound(b))
    return 0ll;
  // cout << "doge" << endl;

  ll res = 1000000000000000ll;
  for (ll c : {a, b}) {
    auto found = points.lower_bound(c);
    if (found != points.end())
      res = min(res, abs(c - *found));
    if (found != points.begin())
      res = min(res, abs(c - *(prev(found))));
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int q;
  ll a, b;
  cin >> q >> a >> b;
  set<ll> points;
  points.insert(a + b);
  points.insert(a - b);
  rep(i, q) {
    int t;
    cin >> t >> a >> b;
    if (t == 1) {
      points.insert(a + b);
      points.insert(a - b);
    } else
      cout << solve(a, b, points) << endl;
  }
  return 0;
}
#endif
