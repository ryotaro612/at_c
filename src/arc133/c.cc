#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(ll h, ll w, ll k, vector<ll> &av, vector<ll> &bv) {
  ll sum_a = 0, sum_b = 0;
  rep(i, h) sum_a += av[i];
  rep(i, w) sum_b += bv[i];
  if (sum_a % k != sum_b % k)
    return -1;

  ll c = 0ll;
  rep(i, h) {
    ll over = ((k - 1ll) * w) % k;
    if (av[i] <= over) {
      c += over - av[i];
    } else { // over < av[i]
      c += over + k - av[i];
    }
  }
  ll d = 0ll;
  rep(i, w) {
    ll over = ((k - 1ll) * h) % k;
    if (bv[i] <= over) {
      d += over - bv[i];
    } else { // over < bv[i]
      d += over + k - bv[i];
    }
  }
  return h * w * (k - 1) - max(c, d);
}

int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  vector<ll> av(h), bv(w);
  rep(i, h) cin >> av[i];
  rep(i, w) cin >> bv[i];
  cout << solve(h, w, k, av, bv) << endl;
  return 0;
}
