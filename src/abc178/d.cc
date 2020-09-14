#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll a[2001];

ll solve(ll s) {
  if(s >= 1 && s<=2) {
    return 0;
  }
  a[0] = 1;
  a[3] = 1;

  for(int i=4;i<2001;i++) {
    a[i] = a[i-3] + a[i-1];
    a[i] %= MOD;
  }
  return a[s];
}
/*
int main() {
  ll s;
  cin >> s;
  cout << solve(s);
}
*/
