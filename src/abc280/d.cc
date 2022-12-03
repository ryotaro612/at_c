#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

map<ll, ll> prime_factorize(ll a) {
  map<ll, ll> result;
  for (ll x = 2ll; x * x <= a; x++) {
    while (a % x == 0) {
      result[x]++;
      a /= x;
    }
  }
  if (a != 1)
    result[a]++;
  return result;
}

#ifdef ONLINE_JUDGE
int main() {
  ll k;
  cin >> k;
  map<ll, ll> prime_factors = prime_factorize(k);

  ll result = 0;
  for (auto [prime, count] : prime_factors) {
    // cout << prime << " -> " << count << endl;
    int temp = 0;
    ll i = 1;
    while (temp < count) {
      ll x = prime * i;
      while (x % prime == 0) {
        x /= prime;
        temp++;
      }
      result = max(result, prime * i);
      i++;
    }
  }

  cout << result << endl;

  return 0;
}
#endif
