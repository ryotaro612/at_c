#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)
const ll MOD = 1000000007ll;

map<ll, ll> prime_factorization(ll num) {
  map<ll, ll> mp;
  for (ll i = 2ll; i * i <= num; i++) {
    while (num % i == 0) {
      mp[i]++;
      num /= i;
    }
  }
  if (num != 1ll)
    mp[num]++;
  return mp;
}

#ifdef ONLINE_JUDGE
int main() {
  ll a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 1 << endl;
    return 0;
  }

  map<ll, ll> mp;
  for (ll i = b + 1; i <= a; i++) {
    map<ll, ll> sub = prime_factorization(i);
    for (auto [prime, freq] : sub) {
      // cout << "doge " << prime << " freq " << freq << endl;
      mp[prime] += freq;
    }
  }
  ll res = 1ll;
  for (auto [prime, freq] : mp) {
    // cout << prime << " -> " << freq << endl;
    res *= (freq + 1ll) % MOD;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
#endif
