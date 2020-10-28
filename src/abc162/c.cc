#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll solve(ll k) {
  ll res = 0;
  for (ll i = 1; i <= k; i++) {
    for (ll j = 1; j <= k; j++) {
      for (ll l = 1; l <= k; l++) {
        res += gcd(gcd(i, j), l);
      }
    }
  }

  return res;
}
/*
int main() {
  ll k;
  cin >> k;
  cout << solve(k);
}
*/