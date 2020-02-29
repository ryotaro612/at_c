#include<iostream>
#include<string>
#include<cstring>

using namespace std;

long long MOD = 1000000007;

long long we_love_abc(string s) {
  long long dp[100001][4];
  memset(dp, 0, sizeof(dp));

  dp[0][0]  = 1;
  if(s[0] == 'A') {
    dp[0][1] = 1;
  } else if(s[0] == '?') {
    dp[0][0] = 3;
    dp[0][1] = 1;
  }
  for(int i=1;i<s.size();i++) {
    // j==0 && s[i] == 'a';
    if(s[i] == 'A') {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
      dp[i][2] = dp[i-1][2];
      dp[i][3] = dp[i-1][3];
      continue;
    }
    if(s[i] == 'B') {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = (dp[i-1][2] + dp[i-1][1]) % MOD;
      dp[i][3] = dp[i-1][3];
      continue;
    }
    if(s[i] == 'C') {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2];
      dp[i][3] = (dp[i-1][3] + dp[i-1][2]) % MOD;
      continue;
    }
    // s[i] == '?'
    for(int j= 0;j<4;j++) {
      dp[i][j] = (dp[i-1][j]*3) % MOD;
    }
    dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
    dp[i][2] = (dp[i][2] + dp[i-1][1]) % MOD;
    dp[i][3] = (dp[i][3] + dp[i-1][2]) % MOD;
  }
  return dp[s.size()-1][3];
}

/*
int main() {
  string s;
  cin >> s;
  cout << we_love_abc(s);
}
*/
