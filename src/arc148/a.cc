#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define icast(i) static_cast<int>(i)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll g = 0ll;
  rep(i, n - 1) { g = gcd(g, abs(av[i] - av[i + 1])); }
  if (g == 1)
    cout << 2;
  else
    cout << 1;
  cout << endl;
  return 0;
}
#endif
