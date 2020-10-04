#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int k, int a, int b) {
  for(int i=a;i<=b;i++) {
    if(i % k == 0)
      return "OK";
  }
  return "NG";
}
/*
int main() {
  int a, b, k;
  cin >> k >> a >> b;
  cout << solve(k, a, b);
}
*/
