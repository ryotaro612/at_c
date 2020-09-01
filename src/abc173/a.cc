#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int a(int n) {
  if(n % 1000 == 0) {
    return 0;
  }
  return  (((int (n / 1000)) + 1) * 1000) - n;
}
/*
int main() {
  int n;
  cin >> n;
  cout << a(n);
}
*/
