#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<string> solve(int t, vector<ll> &av, vector<ll> &sv) {
  vector<string> res(t);
  rep(i, t) {
    ll a = av[i];
    ll s = sv[i];
    ll diff = s - a * 2ll;
    if (diff < 0) {
      res[i] = "No";
    } else {
      if ((diff & a) == 0) {
        res[i] = "Yes";
      } else {
        res[i] = "No";
      }
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  vector<ll> av(t), sv(t);
  rep(i, t) cin >> av[i] >> sv[i];
  vector<string> res = solve(t, av, sv);
  for (auto &e : res)
    cout << e << endl;
  return 0;
}
#endif
