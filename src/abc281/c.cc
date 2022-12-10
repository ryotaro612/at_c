#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  ll t;
  cin >> n >> t;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  ll total = 0ll;
  rep(i, n) total += av[i];
  t %= total;
  ll cursor = 0ll;
  rep(i, n) {
    if (t <= cursor + av[i]) {
      cout << i + 1 << " " << t - cursor << endl;
      return 0;
    }
    cursor += av[i];
  }

  return 0;
}
#endif
