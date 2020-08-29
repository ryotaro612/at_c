#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll d(int n, vector<ll> a) {
  vector<ll> sum(n);
  sum[0] = a[0];
  for(int i=1;i<n;i++) {
    sum[i] = sum[i-1] + a[i]; 
  }

  ll result = numeric_limits<ll>::max();
  
  int c = 1;
  int d = 2;
  int e = 3;
  ll p, q, r, s;
  for(;d<=n-2;d++) {
    if(e <= d) {
      e = d + 1;
    }
    while(c<d-1) {
      if(abs(sum[c-1] - (sum[d-1] - sum[c-1])) < abs(sum[c] - (sum[d-1] - sum[c]))) {
	break;
      }
      c++;
    }
    while(e<n-1) {
      if(abs((sum[n-1] - sum[e-1]) - (sum[e-1] - sum[d-1])) < 
	  abs((sum[n-1] - sum[e]) - (sum[e] - sum[d-1]))) {
	break;
      }
      e++;
    }
    p = sum[c-1];
    q = sum[d-1] - sum[c-1];
    r = sum[e-1] - sum[d-1];
    s = sum[n-1] - sum[e-1];
    result = min(
	abs(max(p, max(q, max(r, s)))- min(p, min(q, min(r, s))))
	, result);
  }

  return result;
  
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0; i< n;i++) {
    cin >> a[i];
  }
  cout << d(n, a);
}
*/
