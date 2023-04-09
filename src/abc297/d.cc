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

ll count(ll a, ll b) {
  if (b == 0)
    return 0;
  ll res = a / b;
  return res + count(b, a % b);
}
#ifdef ONLINE_JUDGE
int main() {
  ll a, b;
  cin >> a >> b;
  cout << count(max(a, b), min(a, b)) - 1ll << endl;
  return 0;
}
#endif
