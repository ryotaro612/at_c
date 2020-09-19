#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n, vector<ll> a) {

  ll res = 0;
  ll sum = 0;
  ll right = 0;
  for(ll left = 0;left<n; left++) {
    while(right < n && (sum ^ a[right]) == (sum + a[right])) {
      sum += a[right];
      right++;
    }

    if(left == right) {
      res++;
    } else {
      res += (right - left);
    }
    sum -= a[left];
  }

  return res;
}
/*
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  cout << solve(n, a);
}
*/

