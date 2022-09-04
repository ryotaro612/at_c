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
  ll n, m;
  cin >> n >> m;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<ll> acc(n + 1, 0);
  rep(i, n) { acc[i + 1] += av[i] + acc[i]; }

  ll temp = 0ll;
  for (ll i = 0; i < m; i++) {
    temp += (i + 1ll) * av[i];
  }
  ll result = temp;
  for (int i = m; i < n; i++) {
    temp -= acc[i] - acc[i - m];
    temp += m * av[i];
    result = max(result, temp);
  }
  cout << result << endl;
  return 0;
}
#endif
