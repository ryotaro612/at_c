#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


ll c(int n, vector<ll> a) {
  for(int i =0;i<n;i++) {
    a[i] -= i + 1;
  }

  sort(a.begin(), a.end());

  int mid = n / 2;
  ll ans = 0;
  for(int i=0;i<n;i++) {
    ans += abs(a[i] - a[mid]);
  }

  return ans;
  
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0; i< n;i++) {
    cin >> a[i];
  }
  cout << c(n, a);
} 
*/
