#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n) {
  int res = 0;
  for(int i=1;i<n;i++) {
    int a = (n-1)/i;
    //cout << i << " x " << a << endl;
    res += a;
  }
  return res;
}
/*
int main() {
  int n;
  cin >> n;
  cout << solve(n);
}
*/
