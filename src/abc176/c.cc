#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll c(vector<ll> a) {
  ll sum = 0;
  ll r = a[0];
  ll len = (ll) a.size();
  for(int i = 1;i<len;i++) {
    if(r > a[i]) {
      sum += r - a[i];
    } else {
      r = a[i];
    }
  }

  return sum;
}
/*
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i =0;i<n;i++) {
    cin >> a[i];
  }
  cout << c(a);
}
*/
