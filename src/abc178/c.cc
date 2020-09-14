#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll p(ll a, int n) {
  ll b = 1;
  for(int i=0;i<n;i++) {
    b *= a;
    b %= MOD;
  }
  return b;

}

ll solve(ll n) {
  if(n == 1) {
    return 0;
  }
  ll res = p(10, n) % MOD;
  res = (res - p(9, n)) % MOD;
  if(res < 0)
    res += MOD;
  res = (res - p(9, n)) % MOD;
  if(res < 0)
    res += MOD;
  res = (res + p(8, n)) % MOD;
  return res;
}
/*
int main() {
  ll n;
  cin >> n;
  cout << solve(n);
}
*/
