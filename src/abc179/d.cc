#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll solve(ll n, ll k, vector<ll> l, vector<ll> r) {
  vector<ll> dp(n, 0), sdp(n+1, 0);
  dp[0] = sdp[1] = 1;

  for(ll i=1;i<n;i++) {
    for(int j=0; j<k; j++) {
      ll left = max(0LL, i-r[j]);
      ll right = max(0LL, i-l[j]+1);
      ll temp = sdp[right] - sdp[left];
      if(temp < 0)
	temp += MOD;
      dp[i] = (temp + dp[i]) % MOD;
    }
    sdp[i+1] = (sdp[i] + dp[i]) % MOD;
  }

  return dp[n-1];
}
/*
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> l(k);
  vector<ll> r(k);
  for(int i=0;i<k;i++) {
    cin >> l[i] >> r[i];
  }
  cout << solve(n, k, l, r);
}
*/
