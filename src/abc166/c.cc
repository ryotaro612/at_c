#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll solve(int n, int m, vector<ll> h, vector<ll> a, vector<ll> b) {
  for(int i=0;i<m;i++) {
    a[i]--;
    b[i]--;
  }
  vector<ll> ma(n, 0);

  for(int i=0;i<m;i++) {
    ma[a[i]] = max(ma[a[i]], h[b[i]]);
    ma[b[i]] = max(ma[b[i]], h[a[i]]);
  }
  ll res = 0;
  for(int i=0;i<n;i++){
    if(h[i] > ma[i])
      res++;
  }
  return res;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n), a(m), b(m);
  for(int i=0;i<n;i++) {
    cin >> h[i];
  }
  for(int i=0;i<m;i++) {
    cin >> a[i] >> b[i];
  }

  cout << solve(n, m, h, a, b);
}
*/
