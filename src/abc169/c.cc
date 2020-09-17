#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, string b) {
  ll bb = (b[0] - '0') * 100 + (b[2] - '0') * 10 + b[3] - '0';
  return (a * bb) / 100;
}
/*
int main() {
  ll a;
  string b;
  cin >> a >> b;
  cout << solve(a, b);
}
*/

