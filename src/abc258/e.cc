#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <numeric>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<ll> solve(ll n, ll q, ll x, vector<ll> &wv, vector<ll> &kv) {
  ll sum = accumulate(wv.begin(), wv.end(), 0ll);
  rep(i, n) { wv.push_back(wv[i]); }
  // 何個入るか
  vector<ll> count(n);
  rep(i, n) { count[i] = n * (x / sum); }
  x %= sum;
  for (int left = 0, right = 0, s = 0; left < n; left++) {
    if (right < left) {
      s = 0;
      right = left;
    }
    while (s < x) {
      s += wv[right++];
    }
    count[left] += right - left;
    s -= wv[left];
  }
  // rep(i, n) cout << i << " -> " << count[i] << endl;

  vector<int> order(n, -1), path;
  int loop, before_loop;
  // i position
  for (int i = 0, j = 0;; j++) {
    if (order[i] == -1) {
      order[i] = j;
      path.push_back(i);
      i = (i + count[i]) % n;
    } else {
      loop = j - order[i];
      before_loop = path.size() - loop;
      break;
    }
  }
  // path, count, loop
  vector<ll> res;
  rep(i, q) {
    ll k = kv[i] - 1;
    if (k < before_loop) {
      res.push_back(count[path[k]]);
    } else {
      res.push_back(count[path[before_loop + (k - before_loop) % loop]]);
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, q, x;
  cin >> n >> q >> x;
  vector<ll> wv(n), kv(q);
  rep(i, n) { cin >> wv[i]; }
  rep(i, q) { cin >> kv[i]; }
  vector<ll> res = solve(n, q, x, wv, kv);
  rep(i, q) { cout << res[i] << endl; }
  return 0;
}
#endif
