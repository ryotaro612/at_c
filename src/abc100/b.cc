#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int b(int d, int n) {

  if(d == 0) {
    if(n==100) {
      return 101;
    }
    return n;
  }
  if(d==1) {
    if(n == 100) {
      return 10100;
    }
    return 100*n;
  }
  if(n == 100) {
    return 1010000;
  }
  return n * 10000;
}

/*
int main() {
  int d, n;
  cin >> d >> n;
  cout << b(d, n);
}
*/
