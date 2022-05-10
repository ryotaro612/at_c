#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<int> eratosthenes(int limit) {
  vector<int> candidates(limit + 1, true);
  vector<int> res;
  for (int i = 2; i < limit + 1; i++) {
    if (candidates[i]) {
      res.push_back(i);
      for (int j = i; j < limit + 1; j += i) {
        candidates[j] = false;
      }
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  vector<int> primes = eratosthenes(1000000ll);
  ll res = 0ll;
  for (int i = 1; i < static_cast<int>(primes.size()); i++) {
    __int128 q = primes[i];
    int lb = -1, ub = i;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      __int128 p = primes[mid];
      if (p * q * q * q <= n) {
        lb = mid;
      } else
        ub = mid;
    }
    res += max(0, lb + 1);
  }
  cout << res << endl;
  return 0;
}
#endif
