#include <iostream>
using namespace std;

long long dp[101][8];
const int mod = 1000000007;

bool valid(int pattern) {
  int before = 0;
  int current;
  while(pattern !=0) {
    current = pattern % 2 == 1 ? 1 : 0;
    if(before == 1 && current == 1) {
      return false;
    }
    before = current;
    pattern = pattern >> 1;
  }
  return true;
} 

long long number_of_amidakuji(int h, int w, int k) {
  for(int i =0;i<101;i++) {
    for(int j=0;j<8;j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;

  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      for(int a=0;a<(1 << (w-1));a++) {
	if (!valid(a))
	  continue;
	if(j==0) {
	  if(a & 1) {
	    dp[i+1][j+1] += dp[i][j] % mod;
	    dp[i+1][j+1] %= mod;
	    continue;
	  }
	  dp[i+1][j] += dp[i][j] % mod;
	  dp[i+1][j] %= mod;
	  continue;
	}
	if(j==w-1) {
	  if(a & (1 << (w-2))) {
	    dp[i+1][j-1] += dp[i][j] % mod;
	    dp[i+1][j-1] %= mod;
	    continue;
	  }
	  dp[i+1][j] += dp[i][j] % mod;
	  dp[i+1][j] %= mod;
	  continue;
	}
	if(a & (1 << (j-1))) {
	  dp[i+1][j-1] += dp[i][j] % mod;
	  dp[i+1][j-1] %= mod;
	  continue;
	}
	if(a & (1 << j)) {
	  dp[i+1][j+1] += dp[i][j] % mod;
	  dp[i+1][j+1] %= mod;
	  continue;
	}
	dp[i+1][j] += dp[i][j] % mod; 
	dp[i+1][j] %= mod;
      }
    }
  }
  return dp[h][k-1];
}
/*
int main() {
  int h, w, k;
  cin >> h;
  cin >> w;
  cin >> k;
  cout << number_of_amidakuji(h, w, k);
}
*/
