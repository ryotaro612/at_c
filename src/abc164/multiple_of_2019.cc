#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dp[200001];
long long multiple_of_2019(string s) {
  int n = (int) s.size();
  int mul = 1;
  for(int i=n-1;i>=0;i--) {
    int digit = (int) s[i] - '0';
    dp[i] = (digit * mul + dp[i+1]) % 2019;
    mul = (mul * 10) % 2019;
  }
  map<int, ll> mp;
  for(int i =0;i<=n;i++) {
    mp[dp[i]] += 1; 
  }
  ll ans = 0;
  for(auto i = mp.begin(); i != mp.end();i++) {
    ll a = i->second;
    ans += a * (a -1) / 2;
  }

  return ans;
}
/*
int main() {
  string s;
  cin >> s;
  cout << multiple_of_2019(s); 
}
*/
