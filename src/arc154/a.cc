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

ll mul(string &a, string &b) {
  ll const MOD = 998244353;

  ll va = 0, vb = 0;
  for (auto c : a) {
    va *= 10ll;
    va %= MOD;
    va += c - '0';
    va %= MOD;
  }
  for (auto c : b) {
    vb *= 10ll;
    vb %= MOD;
    vb += c - '0';
    vb %= MOD;
  }
  return va * vb % MOD;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;

  if (a == b) {
    cout << mul(a, b) << endl;
    return 0;
  }

  if (a < b)
    swap(a, b);

  rep(i, n) {
    if (a[i] < b[i])
      swap(a[i], b[i]);
  }
  // cout << a << " " << b << endl;
  cout << mul(a, b) << endl;

  return 0;
}
#endif
