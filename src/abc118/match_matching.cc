#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

string match_matching(ll n, ll m, ll a[]) {
  ll invalid = -100000000;
  vector<ll> dp(n+1, invalid);
  int b[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  dp[0] = 0;
  for(ll i = 2;i<n+1;i++) {
    ll max_digits = invalid;
    for(int j = 0;j<m;j++) {
      ll required_match = b[a[j] - 1]; // 必要なマッチの本数
      if(i < required_match) {
	continue;
      }
      ll count = dp[i - required_match] + 1;
      max_digits =  max(count, max_digits);
      max_digits = max_digits < 0 ? invalid : max_digits;
    }
    dp[i] = max_digits;
  }

  ll remains = n;
  string ans = "";
  while(remains>0) {
    ll target_digit = a[0];
    for(ll i=0;i<m;i++) {
      ll req_match = b[a[i] - 1];
      if(remains < req_match) {
	continue;
      }
      if(remains < b[target_digit - 1]) {
	target_digit = a[i];
	continue;
      }

      if(dp[remains - req_match] > dp[remains - b[target_digit - 1]]) {
	target_digit = a[i];
	continue;
      }
      if(dp[remains - req_match] == dp[remains - b[target_digit - 1]]) {
	target_digit = target_digit > a[i] ? target_digit : a[i];
	continue;
      }
    }
    remains = remains - b[target_digit - 1];
    ans = ans + to_string(target_digit);
  }

  return ans;
}
/*
int main() {
  ll n, m;
  cin >> n;
  cin >> m;
  ll a[m];

  for(int i=0;i<m;i++) {
    cin >> a[i];
  }
  cout << match_matching(n, m, a);
}
*/
