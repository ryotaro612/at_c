#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <unordered_set>
#include <vector>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) { cin >> grid[i]; }
  ll q;
  cin >> q;

  vector<ll> rv(h, 0);
  vector<ll> cv(w, 0);
  ll dr = 0ll, dc = 0ll;
  rep(i, q) {
    ll a, b;
    cin >> a >> b;
    if (q % 2) {
      if (i % 2) {
        dr -= a;
        dc -= b;
      } else {
        dr += a;
        dc += b;
      }
    } else {
      if (i % 2) {
        dr += a;
        dc += b;
      } else {
        dr -= a;
        dc -= b;
      }
    }
  }

  vector<string> res(h, string(w, ' '));
  for (ll i = 0ll; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      ll r = dr;
      ll c = dc;
      if (q % 2) {
        r -= i + 1;
        c -= j + 1;
      } else {
        r += i;
        c += j;
      }
      r %= h;
      c %= w;
      if (r < 0)
        r += h;
      if (c < 0)
        c += w;
      // cout << r << " " << c << endl;
      res[r][c] = grid[i][j];
    }
  }
  rep(i, h) { cout << res[i] << endl; }
  return 0;
}
#endif
