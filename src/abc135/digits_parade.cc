#include <string>
#include <iostream>

using namespace std;


int to_int(char b) {
  if (b == '?')
    return -1;
  return b - '0';
}

int digits_parade(string s) {
  long long dp[100001][13] = { {0} };

  int digit = to_int(s.at(0)); 
  if(digit == -1) {
    for(int i = 0;i<13;i++) {
      if(i < 10)
	dp[0][i] = 1;
      else
	dp[0][i] = 0;
    }
  } else {
    for(int i = 0;i<13;i++) {
      if(digit == i && digit < 10)
	dp[0][i] = 1;
      else
	dp[0][i] = 0;
    }
  }
  for(int i=1;i<s.length();i++) {
    int digit = to_int(s.at(i));
    if(digit != -1) {
      for(int r = 0;r<13;r++) {
	dp[i][(r*10 + digit) % 13] += dp[i-1][r];
      }
    } else {
      for(int r = 0;r<13;r++) {
	for(int a = 0; a<10; a++) {
	  dp[i][(r*10 + a) % 13] += dp[i-1][r];
	}
      }      
    }
    for(int r =0;r<13;r++) {
      dp[i][r] = dp[i][r] % 1000000007;
    }
  }
  return dp[s.length()-1][5];
}
