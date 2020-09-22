#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b, ll c, ll k) {
  
  if(k <= a)
    return k;
  ll kk = k-a;
  ll points = a;
  if(kk<=b)
    return points;
  kk -= b;
  return points - kk;
}
/*
int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  cout << solve(a, b, c, k);
}
*/
