#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c(ll x, ll k, ll d) {
  if(x == 0) {
    if(k % 2 == 0) {
      return 0;
    }
    return d;
  }
  ll xx = x > 0? x : -1 * x;
  ll offset = xx / d;
  if(offset >= k) {
    return xx - (k*d);
  }
  // offset < k
  ll kk = k - offset;
  ll base = xx - (offset * d);

  if(kk % 2==0) {
    return base;
  }
  return abs(base-d);
}
/*
int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  cout << c(x, k, d);
}
*/
