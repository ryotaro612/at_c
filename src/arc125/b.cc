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

#ifdef ONLINE_JUDGE
int main() {
  long long N, ans = 0;
  cin >> N;

  const long long MOD = 998244353;
  for (long long q = 1; q * q <= N; q++) {
    ans += (N / q - q) / 2 + 1;
    ans %= MOD;
  }
  cout << ans << endl;
}
#endif
