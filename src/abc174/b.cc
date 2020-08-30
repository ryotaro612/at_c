#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll b(ll n, ll d, vector<ll> x, vector<ll> y) {
  ll res = 0; 
  for(int i=0;i<n;i++) {
    if((x[i] * x[i] + y[i] * y[i]) <= d * d) {
      res++;
    }
  }
  return res;
}
/*
int main() {
  ll n, d;
  cin >> n >> d;
  vector<ll> x(n);
  vector<ll> y(n);
  for(int i=0;i<n;i++) {
    cin >> x[i] >> y[i];
  }
  cout << b(n, d,x, y);
}
*/
