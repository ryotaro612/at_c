#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
  ll res = 0;
  for (ll i = 1; i <= n; i++) {
    if (i % 3 != 0 && i % 5 != 0) {
      res += i;
    }
  }
  return res;
}
/*
int main() {
  ll n;
  cin >> n;
  cout << solve(n);
}
*/