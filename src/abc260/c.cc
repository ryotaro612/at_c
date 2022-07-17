#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

void compute_blue(ll i, vector<ll> &reds, vector<ll> &blues, ll x, ll y) {
  blues[i] = reds[i - 1] + blues[i - 1] * y;
}
void compute_red(ll i, vector<ll> &reds, vector<ll> &blues, ll x, ll y) {
  reds[i] = reds[i - 1] + blues[i] * x;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> reds(11, -1), blues(11, -1);
  reds[1] = 0ll;
  blues[1] = 1ll;
  for (int i = 2; i <= n; i++) {
    compute_blue(i, reds, blues, x, y);
    compute_red(i, reds, blues, x, y);
  }
  cout << reds[n] << endl;
  return 0;
}
#endif
