#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int solve(int a, int b) {
  if(a <= b) {
    return a;
  }
  return a-1;
}
/*
int main() {
  int a, b;
  cin >> a >> b;
  cout << solve(a, b);
}
*/
