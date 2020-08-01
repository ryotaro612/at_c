#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


vector<ll> rain_flows_into_dams(vector<ll> a) {
  vector<ll> ans;

  ll acc = 0;
  for(ll i = 0;i<a.size();i++) {
    if(i % 2 == 0) {
      acc += a.at(i);
    } else {
      acc -= a.at(i);
    }
  }
  ans.push_back(acc);
  for(ll i = 0; i<a.size()-1;i++) {
    ll y = ans.at(i) / 2;
    ans.push_back((a.at(i) - y)*2);
  }
  return ans;
}
/*

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);

  for(ll i= 0;i<n;i++) {
    cin >> a[i];
  }
  vector<ll> ans = rain_flows_into_dams(a);

  for(ll i =0; i < ans.size();i++) {
    cout << ans[i];
    if(i != ans.size() - 1) {
      cout << " ";
    }
  }
}
*/
