#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b, ll c, ll d) {
  return max(a * c, max(a*d, max(b*c, b*d)));
}
/*
int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << solve(a, b, c, d);
}
*/
