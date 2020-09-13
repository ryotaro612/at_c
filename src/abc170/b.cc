#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int b(int x1, int x2, int x3, int x4, int x5) {
  if(x1 == 0) {
    return 1;
  }
  if(x2 == 0) {
    return 2;
  }
  if(x3 == 0) {
    return 3;
  }
  if(x4 == 0) {
    return 4;
  }
  return 5;
}
/*
int main() {
  int x1, x2, x3, x4, x5;
  cin >> x1 >> x2 >> x3 >> x4 >> x5;
  cout << a(x1, x2, x3, x4, x5);
}
*/
