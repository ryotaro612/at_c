#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Line {
  ll a, b, c;
  bool operator==(const Line &other) const {
    return other.a == a && other.b == b && other.c == c;
  }
};

struct LineHash {
  size_t operator()(const Line &l) const {
    size_t seed = 0;
    auto a_hash = hash<ll>()(l.a);
    auto b_hash = hash<ll>()(l.b);
    auto c_hash = hash<ll>()(l.c);
    seed ^= a_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= b_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= c_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};

Line calc_line(ll x1, ll y1, ll x2, ll y2) {
  ll a = y1 - y2;
  ll b = x2 - x1;
  ll c = -(y1 * x2) + x1 * y2;
  // cout << a << " " << b << " " << c << " @@@ " << endl;
  ll g = __gcd(__gcd(a, b), c);
  a /= g;
  b /= g;
  c /= g;
  // cout << "g " << g << endl;
  if (a < 0) {
    a = -a;
    b = -b;
    c = -c;
  }
  if (a == 0) {
    if (b < 0) {
      b = -b;
      c = -c;
    }
  }
  // cout << a << " " << b << " " << c << " XXX " << endl;
  return {a, b, c};
}

pair<ll, ll> normalization(ll up, ll down, bool slope = true) {
  if (down < 0) {
    up *= -1;
    down *= -1;
  }

  if (down == 0) {
    if (slope)
      up = 1;
  } else {
    ll g = gcd(abs(up), down);
    up /= g;
    down /= g;
  }

  return {up, down};
}

tuple<ll, ll, ll, ll> c_line(ll x1, ll y1, ll x2, ll y2) {
  ll dx = x1 - x2;
  ll dy = y1 - y2;

  tie(dy, dx) = normalization(dy, dx);

  // ya = dy * xa / dx + b
  // b = (ya * dx - dy * xa) / dx

  ll bup = y1 * dx - dy * x1;
  ll bdown = dx;

  tie(bup, bdown) = normalization(bup, bdown, false);
  return {dy, dx, bup, bdown};
}

struct TupleHash {
  size_t operator()(const tuple<ll, ll, ll, ll> &x) const {
    size_t seed = 0;
    auto a_hash = hash<ll>()(get<0>(x));
    auto b_hash = hash<ll>()(get<1>(x));
    auto c_hash = hash<ll>()(get<2>(x));
    auto d_hash = hash<ll>()(get<3>(x));
    seed ^= a_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= b_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= c_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= d_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};

int solve(int n, int k, vector<ll> &xv, vector<ll> &yv) {
  if (k == 1) {
    return -1;
  }
  map<tuple<ll, ll, ll, ll>, ll> count;
  rep(i, n) {
    for (int j = i + 1; j < n; j++) {
      auto line = c_line(xv[i], yv[i], xv[j], yv[j]);
      count[line]++;
      // count[line].insert({xv[i], yv[i]});
      // count[line].insert({xv[j], yv[j]});
    }
  }

  map<int, int> rcomb;
  for (int i = k; i < n + 1; i++) {
    rcomb[i * (i - 1) / 2] = 1;
  }
  int ans = 0;
  for (auto p : count) {
    ans += rcomb[p.second];
  }
  return ans;
  // int res = 0;
  // for (auto e : count) {
  //   // if (static_cast<int>(e.second.size()) >= k * (k - 1) / 2ll)
  //   //   res++;
  //   if (e.second >= k * (k - 1ll) / 2ll)
  //     res++;
  // }
  // return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> xv(n), yv(n);
  rep(i, n) { cin >> xv[i] >> yv[i]; }
  int result = solve(n, k, xv, yv);
  if (result >= 0)
    cout << result;
  else
    cout << "Infinity";
  cout << endl;
  return 0;
}
#endif
