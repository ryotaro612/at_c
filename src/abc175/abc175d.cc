#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[5001][5001];
ll cycle[5001];

ll M_INF = -100000000000000; // 9,223,372,036,854,775,808

ll abc175d(ll n, ll k, ll p[], ll c[]) {
  map<ll, ll> direct;
  for(ll i=0;i<n;i++) {
    direct[i] = p[i] - 1;
  }

  for(ll i=0;i<n;i++) {
    ll count = 1;
    ll cur = direct[i];
    dp[i][0] = c[cur];
    while(cur != i) {
      cur = direct[cur];
      dp[i][count] = c[cur] + dp[i][count-1];
      count++;
    }
    cycle[i]=count;
  }

  ll res = M_INF;

  for(ll i=0;i<n;i++) {
    if(dp[i][cycle[i]-1] <= 0) {
      ll kk = min(k, cycle[i]);
      ll r = M_INF;
      for(ll j = 0;j<kk;j++) {
	r = max(r, dp[i][j]); 
      }
      res = max(res, r);
      continue;
    }
    ll r = 0;
    ll kk = k;
    ll rr = M_INF;
    if(k/cycle[i] > 1) {
      r = ((k/cycle[i]) - 1) * dp[i][cycle[i]-1];
      kk -= cycle[i] * ((k/cycle[i]) - 1);
      rr = 0;
    }
    if(kk<=cycle[i]) {
      for(ll j = 0;j<kk;j++) {
	rr = max(rr, dp[i][j]);
      }
      res = max(res, r + rr);
      continue;
    }

    ll mx = M_INF;
    for(ll j=0;j<cycle[i];j++) {
      mx = max(mx, dp[i][j]);
    }
    kk -= cycle[i]; 
    for(ll j = 0;j<kk;j++) {
      rr = max(rr, dp[i][j]);
    }
    res = max(res, max(r + dp[i][cycle[i]-1] + rr, r + mx));
  }
  return res;
}
/*
int main() {
  ll n, k;
  cin >> n >> k;
  ll p[n], c[n];
  for(ll i = 0; i< n;i++) {
    cin >> p[i];
  }
  for(ll i = 0; i< n;i++) {
    cin >> c[i];
  }
  cout << abc175d(n, k, p, c);
}
*/
