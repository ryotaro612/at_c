#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(int x) {
  if(x==1) {
    return 1;
  }
  int res = 0;
  for(int i = 2;pow(i, 2) <=x;i++) {
    for(int j=2;pow(i, j)<=x;j++) {
      res = max(res, (int) pow(i,j));
    }
  }
  return res;
}
/*
int main() {
  int x;
  cin >> x;
  cout << solve(x);
}
*/
