#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(const int n, const int m, ll x, vector<ll> c, vector<vector<ll>> a) {
  const int bit = 1 << n;
  ll res = -1;
  for(int i=0; i< bit; i++) {
    ll cost = 0;
    vector<ll> temp(m, 0);
    for(int j=0;j<n;j++) {
      if(i & (1 << j)) {
	cost += c[j];
	for(int k=0;k<m;k++) {
	  temp[k] += a[j][k];
	}
      }
    }
    for(int j=0;j<m;j++) {
      if(temp[j] < x) {
	break;
      }
      if(j==m-1) {
	res = res == -1 ? cost : min(cost, res);
      }
    }
  }
  return res;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  ll x;
  cin >> x;
  vector<ll> c(n);
  vector<vector<ll>> a(n, vector<ll>(m));
  for(int i=0;i<n;i++) {
    cin >> c[i];
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, m, x, c, a);
}
*/
