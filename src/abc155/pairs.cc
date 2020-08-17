#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1LL<<61;

long long pairs(ll n, ll k, vector<ll> a) {
  sort(a.begin(), a.end());

  long long left = -INF, right = INF;

  while(right > left + 1) {
    long long x = (left + right) / 2;
    long long s = 0, t = 0;

    for(int i=0;i<n;i++) {
      if(a[i] > 0) {
	ll l2 = -1, r2 = n;
	while(r2 > l2 + 1) {
	  ll m = (l2 + r2) / 2;
	  if(a[i] * a[m] <= x) l2 = m;
	  else r2 = m;
	}
	s += r2;
      }
      else if (a[i] < 0) {
	ll l2 = -1, r2 = n;
	while(r2 > l2 + 1) {
	  ll m = (l2 + r2) / 2;
	  if(a[i] * a[m] <= x) {
	    r2 = m;
	  } else l2 = m;
	}
	s += n - r2;
      }
      else if (x >= 0) s+= n;
      if(a[i] * a[i] <= x) ++ t;
    }
    long long num = (s-t) / 2;
    if(num >= k) right = x;
    else left = x;
  }

  return right;
}
/*
int main() {
  ll n, k;
  cin >> n;
  cin >> k;
  vector<long long> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << pairs(n, k, a);
}
*/
