#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll calc(ll a, ll b) {
  ll move_time = (b-a) / 3ll;
  return a + move_time + move_time * 2ll;
}

ll solve(ll r, ll g, ll b) {
  const ll inf = 10e16;
  //cout << inf << endl;
  ll res = inf;
  if((r - g) % 3ll == 0ll) {
  	res = min(res, calc(min(r, g), max(r, g)));
  }
  if((g - b) % 3ll == 0ll) {
  	res = min(res, calc(min(b, g), max(b, g)));  
  } 
  if((r - b) % 3ll == 0ll) {
   	res = min(res,calc(min(r, b), max(r, b))); 
  }
  if(res == inf)
    return -1ll;
  return res;
}

#ifndef _debug
int main() {
    int t;
    cin >> t;
    vector<ll> r(t), g(t), b(t);
    rep(i, t) cin >> r[i] >> g[i] >> b[i];
    rep(i, t) {
      // cout << "i: " << i << endl;
      cout << solve(r[i], g[i], b[i]) << endl;
    }
    return 0;
}
#endif