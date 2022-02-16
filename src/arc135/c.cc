#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll solve(int n, vector<ll> &av) {
  ll res = 0ll;
  rep(i, n) res += av[i];
  vector<int> ones(30, 0);
  rep(i, 30) {
    rep(j, n) {
      if (av[j] & 1 << i) {
        ones[i]++;
      }
    }
  }
  rep(i, n) {
    ll temp = 0ll;
    rep(j, 30) {
      ll unit = 1 << j;
      if (av[i] & (1 << j)) {
        temp += unit * (ll)(n - ones[j]);
      } else {
        temp += unit * ones[j];
      }
    }
    res = max(temp, res);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  cout << solve(n, av) << endl;
  return 0;
}
#endif
