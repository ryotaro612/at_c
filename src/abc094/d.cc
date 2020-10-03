#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


pair<ll, ll> solve(int n, vector<ll> a) {
  sort(a.begin(), a.end());
  ll a_i = a[n-1];
  ll a_j = a[0];
  if(a_i % 2 == 0) {
    for(int i=0;i<n-1;i++) {
      if(abs(a[i]- a_i/2) < abs(a_j - a_i/2)) {
	a_j = a[i];
      }
    }
    return make_pair(a_i, a_j);
  }
  for(int i=0;i<n-1;i++) {
      //cout << a[i] << " " << abs(a[i]- a_i/2) << endl;
      if(abs(a[i]- a_i/2) < abs(a_j - a_i/2)) {
	a_j = a[i];
      }
  }
  for(int i=0;i<n-1;i++) {
      if(abs(a[i]- (a_i/2+1)) < abs(a_j - (a_i/2+1))) {
	a_j = a[i];
      }
  }
  return make_pair(a_i, a_j);
}
/*
int main() {
  int n; 
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) {
     cin >> a[i];
  }
  auto res = solve(n, a);
  cout << res.first << " " << res.second;
}
*/
