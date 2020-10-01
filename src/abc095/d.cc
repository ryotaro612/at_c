#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll solve(ll n, ll c, vector<ll> x, vector<ll> v) {

  ll res = 0;
  vector<ll> s(n);
  s[0] = v[0];
  for(ll i=1;i<n;i++) {
    s[i] = s[i-1] + v[i];
  }
  // clockwise
  for(ll i=0;i<n;i++) {
    res = max(s[i] - x[i], res);
  }
  // counter clockwise
  for(ll i=n-1;i>=1;i--) {
    res = max((s[n-1] - s[i-1]) - (c-x[i]) , res);
  }
  res = max(s[n-1] - (c-x[0]), res);

  if(n<=1)
    return res;
  // n >= 2
  vector<ll> a(n-1);
  a[n-2] = s[n-1] - s[n-2] - (c-x[n-1]);
  for(ll i=n-3;i>=0;i--) {
    a[i] = max((s[n-1] - s[i]) - (c - x[i+1]), a[i+1]);
  }
  // oa + ab = 2oa + ob
  for(ll i=0;i<n-1;i++) {
    ll vv = s[i]; // 2oa
    ll xx = 2*x[i]; // 2oa
    res = max(vv - xx + a[i], res);
  }
 
  // 2ob + oa
  vector<ll> b(n, 0);
  b[1] = s[0] - x[0];
  for(ll i=2;i<n;i++) {
    b[i] = max(s[i-1] - x[i-1], b[i-1]);
  }

  for(ll i = n-1;i>0;i--) {
    ll vv = s[n-1] - s[i-1];
    ll xx = 2 * (c - x[i]);
    res = max(vv - xx + b[i], res);
  }

  return res;
}
/*
int main() {
  ll n, c;
  cin >> n >> c;
  vector<ll> x(n), v(n);

  for(ll i=0;i<n;i++) {
    cin >> x[i] >> v[i];
  }
  cout << solve(n, c, x, v);
}
*/
