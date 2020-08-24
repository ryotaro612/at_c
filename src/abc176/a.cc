#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int a(int n, int x, int t) {
  int ans = (n / x) * t;
  if(n % x == 0) {
    return ans;
  }
  return ans + t;
}
/*
int main() {
  int n, x, t;
  cin >> n >> x >> t;
  cout << a(n, x, t);
}
*/
