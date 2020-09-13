#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int a, int b) {

  int d = b - a;
  int h = 0;
  for(int i=1;i<=d-1;i++) {
    h +=i;
  }

  return h - a;
}
/*
int main() {
  int a, b;
  cin >> a >> b;

  cout << solve(a, b);
}

*/
