#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll b(ll n, vector<ll> a) {
  sort(a.begin(), a.end());
  return abs(a[n-1] - a[0]);
}
/*
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i =0;i<n;i++) {
    cin >> a[i];
  }
  cout << b(n, a);
}
*/
