#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

const ll MOD = 998244353ll;
ll mypow(ll x, ll n) {
  ll res = 1ll;
  while (n) {
    if (n & 1) {
      res *= x;
      res %= MOD;
    }

    n >>= 1;
    x *= x;
    x %= MOD;
  }
  return res;
}

long long modinv(long long a) {
  ll m = MOD;
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

ll solve(int r, int c, vector<vector<ll>> &dp,
         map<pair<int, int>, char> &defined) {
  if (dp[r][c] != -1)
    return dp[r][c];
  ll res = 0ll;
  int h = dp.size();
  int w = dp[0].size();

  if (r < h - 1) {
    if (defined.count({r, c})) {
      if (defined[{r, c}] != 'R') {
        res += solve(r + 1, c, dp, defined);
        res %= MOD;
      }
    } else {
      res += solve(r + 1, c, dp, defined) * 2ll % MOD * modinv(3ll) % MOD;
      res %= MOD;
    }
  }
  if (c < w - 1) {
    if (defined.count({r, c})) {
      if (defined[{r, c}] != 'D') {
        res += solve(r, c + 1, dp, defined);
        res %= MOD;
      }
    } else {
      res += solve(r, c + 1, dp, defined) * 2ll % MOD * modinv(3ll) % MOD;
      res %= MOD;
    }
  }
  return dp[r][c] = res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int h, w, k;
  cin >> h >> w >> k;

  map<pair<int, int>, char> defined;
  rep(i, k) {
    int h, w;
    char c;
    cin >> h >> w >> c;
    defined[{--h, --w}] = c;
  }
  vector<vector<ll>> dp(h, vector<ll>(w, 0ll));
  dp[0][0] = 1;
  rep(r, h) {
    rep(c, w) {
      if (defined.count({r, c})) {
        char letter = defined[{r, c}];
        if (letter != 'D') {
          if (c < w - 1) {
            dp[r][c + 1] += dp[r][c];
            dp[r][c + 1] %= MOD;
          }
        }
        if (letter != 'R') {
          if (r < h - 1) {
            dp[r + 1][c] += dp[r][c];
            dp[r + 1][c] %= MOD;
          }
        }
      } else {
        if (r < h - 1) {
          dp[r + 1][c] += dp[r][c] * 2ll % MOD * modinv(3ll) % MOD;
          dp[r + 1][c] %= MOD;
        }
        if (c < w - 1) {
          dp[r][c + 1] += dp[r][c] * 2ll % MOD * modinv(3ll) % MOD;
          dp[r][c + 1] %= MOD;
        }
      }
    }
  }
  ll res = dp[h - 1][w - 1] * mypow(3ll, h * w - k) % MOD;
  // rep(i, h) {
  //   rep(j, w) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  cout << res << endl;
  return 0;
}
//#endif
