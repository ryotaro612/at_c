#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c(int n, int m, ll k, vector<ll> a, vector<ll> b) {
 
  vector<ll> a_sum(n+1, 0);
  for(int i=0;i<n;i++) {
    a_sum[i+1] = a_sum[i] + a[i];
  }
  vector<ll> b_sum(m+1, 0);
  for(int i=0;i<m;i++) {
    b_sum[i+1] = b_sum[i] + b[i];
  }
 
  ll j = m;
  ll ans = 0;
  for(int i =0;i<=n;i++) {
    if(a_sum[i] > k)
      break;

    while(b_sum[j] > k - a_sum[i]) {
      j--;
    }
    ans = max(ans, i + j);
  }
  return ans;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  ll k;
  cin >> k;
  vector<ll> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i]; 
  }
  vector<ll> b(m);
  for(int i=0;i<m;i++) {
    cin >> b[i]; 
  }
  cout << c(n, m, k, a, b);

}
*/
