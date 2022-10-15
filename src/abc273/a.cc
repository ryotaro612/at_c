#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
ll f(ll n) {
  if (n == 0)
    return 1ll;
  return n * f(n - 1);
}

#ifdef ONLINE_JUDGE
int main() {
  ll n;
  cin >> n;
  cout << f(n) << endl;
  return 0;
}
#endif
