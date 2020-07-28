#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

long long enough_array(ll a[], ll n, ll k) {
  ll ans = 0;
  ll sum = 0;
  int r = 0;

  for(int l=0;l<n;l++) {
    while(sum < k) {
      if(r >= n) {
	break;
      }
      sum += a[r];
      r++;
    }
    if(sum >= k) {
      sum -= a[l];
      ans += n - r + 1;
    }

  }
  return ans;
}
/*
int main() {
  ll n;
  ll k;
  cin >> n;
  cin >> k;
  ll a[n];
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << enough_array(a, n, k);
}
*/
