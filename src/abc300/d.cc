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

vector<ll> enumerate_primes(int n) {
  vector<bool> shieve(n, true);
  vector<ll> res;
  for (int i = 2; i < n; i++) {
    if (shieve[i]) {
      res.push_back(i);
      for (int j = i * 2; j < n; j += i)
        shieve[j] = false;
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n, res = 0;
  cin >> n;
  vector<ll> primes = enumerate_primes(300000);
  int n_primes = primes.size();

  rep(i, n_primes) {
    ll a = primes[i];
    for (int j = i + 1; j < n_primes - 1; j++) {
      ll b = primes[j];
      int lb = j, ub = n_primes;
      while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        ll c = primes[mid];
        if (a <= n && a * b <= n && a * b * c <= n && a * a <= n &&
            a * a * b <= n && a * a * b * c && 0 < a * a * b * c * c &&
            a * a * b * c * c <= n)
          lb = mid;
        else
          ub = mid;
      }
      if (lb - j > 0) {
        res += lb - j;
      } else
        break;
    }
  }
  cout << res << endl;
  return 0;
}
#endif
