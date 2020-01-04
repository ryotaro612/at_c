#include <iostream>
using namespace std;

int a = 0;
int g = 1;
int c = 2;
int t = 3;

long long we_like_agc(int n){
  long long mod = 1000000007;
  long long ans[100][4][4][4][4] = {{{{{0}}}}};

  if(n == 3)
    return 61;
  for(int j=0;j<4;j++) {
    for(int k=0;k<4;k++) {
      for(int l=0;l<4;l++) {
	for(int m=0;m<4;m++) {
	  ans[3][j][k][l][m] = 0;
	  if((j == a && k == g && l == c) || 
	     (j == g && k == a && l == c) || 
	     (j == a && k == c && l == g) || 
	     (j == a && k == g &&           m == c) || 
	     (          k == a && l == g && m == c) ||
	     (j == a           && l == g && m == c) || 
	     (          k == g && l == a && m == c) ||
	     (          k == a && l == c && m == g)){
	    continue;
	  }
	  ans[3][j][k][l][m] = 1;
	}
      }
    }
  }

  for(int i=4;i<n;i++) {
    for(int j=0;j<4;j++) {
      for(int k=0;k<4;k++) {
	for(int l=0;l<4;l++) {
	  for(int m=0;m<4;m++) {
	    ans[i][j][k][l][m] = 0;
	  if((j == a && k == g && l == c) || 
	     (j == g && k == a && l == c) || 
	     (j == a && k == c && l == g) || 
	     (j == a && k == g &&           m == c) || 
	     (          k == a && l == g && m == c) ||
	     (j == a           && l == g && m == c) || 
	     (          k == g && l == a && m == c) ||
	     (          k == a && l == c && m == g)){
	    continue;
	  }
	  for(int o = 0;o<4;o++) {
	    ans[i][j][k][l][m] += ans[i-1][o][j][k][l];
	    ans[i][j][k][l][m] = ans[i][j][k][l][m] % mod;
	  }
	  }
	}
      }
    }
  }

  long long rtn = 0;
  for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++) {
      for(int k=0;k<4;k++) {
	for(int l=0;l<4;l++) {
	  rtn += ans[n-1][i][j][k][l];
	  rtn = rtn % mod;
	}
      }
    }
  }

  return rtn;
}
/*
int main() {
  int n;
  cin >> n;
  cout << we_like_agc(n);
}
*/
