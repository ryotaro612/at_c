#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long xxor(long long n, long long k, long long a []) {
  if(k==0) {
    long long ans = 0; 
    for(int i=0;i<n;i++) {
      ans += a[i];
    }
    return ans;
  }
  auto kk = k;
  int bit_count = 0;
  while(kk > 0) {
    kk = kk >> 1;
    bit_count++;
  }
  long long dp[bit_count][2];
  for(int i=bit_count;i>0;i--) {
    long long mask = 1LL << (i-1);
    long long count1 = 0;
    for(int j=0;j<n;j++) {
      if(mask & a[j]) {
	count1++;
	continue;
      }
    }
    long long count0 = n - count1; 
    if(i == bit_count) {
      dp[i][0] = mask * count0;
      dp[i][1] = mask * count1;
      continue;
    }
    if(k & mask) {
      dp[i][0] = dp[i+1][0] + mask*count0;
      dp[i][1] = max(dp[i+1][0] + mask*count1, max(dp[i+1][1] + mask*count0, dp[i+1][1] + mask*count1));
      continue;
    }
    dp[i][0] = dp[i+1][0] + mask*count1;
    dp[i][1] = max(dp[i+1][1] + mask*count1, dp[i+1][1] + mask*count0);
  }
  return max(dp[1][0], dp[1][1]);
}
/*
int main() {
  long long n, k;
  cin >> n;
  cin >> k;
  long long a[n];
  for(long long i=0;i<n;i++) {
    cin >> a[i]; 
  }
  cout << xxor(n, k, a);
}
*/
