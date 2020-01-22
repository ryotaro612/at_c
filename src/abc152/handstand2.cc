#include<iostream>
#include<string>
using namespace std;

long long handstand2(int n) {
  long long memo[10][10];
  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++) {
      memo[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++) {
    if(i>0 && i<10) {
      memo[i][i] += 1;
      continue;
    }
    string s = to_string(i);
    int a = s[0] - '0';
    int b = s[s.size() - 1] - '0';
    memo[a][b] += 1;
  }
  long long  ans = 0;
  for(int a=0;a<10;a++) {
    for(int b=0;b<10;b++) {
      ans += memo[a][b] * memo[b][a];
    }
  }
  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  cout << handstand2(n);
}
*/
