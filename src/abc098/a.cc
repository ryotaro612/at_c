#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int a, int b) {
  return max(a+b, max(a-b, a*b));
}
/*
int main() {
  int a, b;
  cin >> a >> b;
  cout << solve(a, b);
}
*/
