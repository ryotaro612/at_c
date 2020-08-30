#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll c(int n, vector<ll> a) {
  vector<ll> sum(n);
  sum[0] = a[0];
  sum[0] %= mod;
  for(int i=1;i<n;i++) {
    sum[i] = sum[i-1] + a[i];
  }
  ll ans = 0;
  for(int i=0;i<n-1;i++) {
    ans += ((a[i] * ((sum[n-1] - sum[i]) % mod)) % mod);
    ans %= mod;
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << c(n, a);
}
*/
