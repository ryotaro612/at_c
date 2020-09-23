#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

string solve(int a, int b, int c, int d) {
  return abs(a-c) <=d || (abs(a - b) <= d && abs(b -c) <= d) ? "Yes" : "No";
}
/*
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << solve(a, b, c, d);
}
*/
