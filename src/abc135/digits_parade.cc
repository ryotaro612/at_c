#include <string>
#include <cmath>
#include <limits>
#include <iostream>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;
ull mod = 1000000007;


ull to_digit(char b) {
  if(b == '?')
    return -1;
  return b - '0';
}

ull dp[100001][13];


ull mod_pow(int a, int num_ten) {
  ull res = 1;
  for(int i =1;i<=num_ten; i++) {
    res *= 10;
    res %= mod;
  }
  res *= a;
  res %= mod;
  return res % 13;
}

ull digits_parade(string s) {

  ull digit = to_digit(s[0]);
  if(digit == -1) {
    for(int i=0;i<10; i++) {
      dp[1][i] = 1;
    }
  } else {
    dp[1][digit] = 1;
  }
  int length = (int) s.size();
  if(length == 1) {
    return dp[1][5];
  }
  for(int i=1; i< length; i++) {
    ull digit = to_digit(s[i]);
    if(digit != -1) {
      for(int j=0;j<13;j++) {
	dp[i+1][((j*10) + digit) % 13] = dp[i][j];
      }
    } else {
      for(int j=0; j<10; j++) {
	for(int k=0;k<13;k++) {
	  dp[i+1][((k*10) + j) % 13] += dp[i][k];
	  dp[i+1][((k*10) + j) % 13] %= mod;
	}
      }
    }
  }
  return dp[length][5];
}
/*
   int main() {
   string s;
   cin >> s;
   cout << digits_parade(s);
   }
*/
