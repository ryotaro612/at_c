#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(arg) cout << #arg << ": " << arg << endl;

ll solve(ll l, ll w, vector<ll> &av) {
  ll res = 0ll, cover = 0ll;
  for (auto &a : av) {
    // cout << a << ", cover: " << cover << ", res: " << res << endl;
    if (cover < a) {
      ll delta = (a - cover + w - 1ll) / w;
      res += delta;
      cover += delta * w;
    }
    cover = max(a + w, cover);
  }
  // cout << "cover: " << cover << ", " << res << endl;
  if (l <= cover) {
    return res;
  }
  // cover < l
  return res + (l - cover + w - 1ll) / w;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll l, w;
  cin >> n >> l >> w;
  vector<ll> av(n);
  rep(i, n) { cin >> av[i]; }
  cout << solve(l, w, av) << endl;
}
#endif
