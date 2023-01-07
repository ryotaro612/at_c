#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

vector<ll> enum_primes() {

  vector<bool> primes(3000001, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i < as_int(primes.size()); i++) {
    if (primes[i]) {
      for (int j = i + i; j < as_int(primes.size()); j += i) {
        primes[j] = false;
      }
    }
  }
  vector<ll> res;
  rep(i, primes.size()) {
    if (primes[i])
      res.push_back(i);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int t;
  cin >> t;
  vector<ll> primes = enum_primes();
  rep(i, t) {
    ll a;
    cin >> a;
    for (auto prime : primes) {
      ll power = prime * prime;
      if (a % power == 0) {
        cout << prime << " " << (a / power) << endl;
        break;
      } else if (a % prime == 0) {
        cout << ll(sqrt(a / prime)) << " " << prime << endl;
        break;
      }
    }
  }
  return 0;
}
#endif
