#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<ll> av(n), prefix(n + 1, 0);
  rep(i, n) cin >> av[i];
  sort(av.begin(), av.end(), greater<ll>());
  rep(i, n) prefix[i + 1] = prefix[i] + av[i];
  for (ll i = p; i < n; i++) {
    if (av[i] + m < av[p - 1]) {
      cout << i << endl;
      return 0;
    }
    ll count = (p - 1ll) * m + m + (n - 1ll - i) * m;
    count += (i - (p - 1ll)) * (m + av[i]) - (prefix[i] - prefix[p - 1]);
    if (count < m * v) {
      cout << i << endl;
      return 0;
    }
  }

  cout << n << endl;
  return 0;
}
#endif
