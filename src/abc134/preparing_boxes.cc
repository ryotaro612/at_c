#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;

vector<ll> preparing_boxes(vector<ll> a) {
  ll n = (ll) a.size();
  vector<ll> ans(n);
  vector<ll> res;
  for(ll i=n-1;i>=0;i--) {
    ll offset = i+1;
    ll j = i + offset;
    ll acc = 0;
    while(j < n) {
      acc += ans[j];
      j += offset;
    }
    if(a[i] == 0) {
      if(acc % 2 == 0) {
	ans[i] = 0;
      } else {
	ans[i] = 1;
	res.push_back(i+1);
      }
    } else {
      if(acc % 2 == 0) {
	ans[i] = 1;
	res.push_back(i+1);
      } else {
	ans[i] = 0;
      }
    }
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
 vector<ll> ans = preparing_boxes(a);
 cout << ans.size() << endl;
 for(ll i=0;i< (ll) ans.size();i++) {
   cout << ans[i];
   if(i != (ll) ans.size() -1) {
     cout << " ";
   }
 }
}
*/
