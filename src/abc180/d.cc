#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll solve(ll x, ll y, ll a, ll b) {
  ll res = 0;
  ll xx = x;
  while ((double)a * xx <= 2e18 && xx * a <= xx + b && xx * a < y) {
    xx *= a;
    res++;
  }
  if (xx * a > y && xx + b > y) {
    return res;
  }

  ll at = (y - 1 - xx) / b;
  if (at > 0) {
    res += at;
  }

  return res;
}
/*
int main() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  cout << solve(x, y, a, b);
}
*/