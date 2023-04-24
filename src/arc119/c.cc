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
  int n;
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  vector<ll> prefix_sum(n, 0);
  map<ll, int> count;
  rep(i, n) {
    if (i == 0)
      prefix_sum[i] = av[i];
    else if (i % 2)
      prefix_sum[i] = prefix_sum[i - 1] - av[i];
    else
      prefix_sum[i] = prefix_sum[i - 1] + av[i];
    count[prefix_sum[i]]++;
  }
  // rep(i, n) cout << prefix_sum[i] << " ";
  // cout << endl;

  ll res = 0ll;
  rep(i, n) {
    if (i == 0) {
      res += count[0];
    } else {
      res += count[prefix_sum[i - 1]];
    }
    count[prefix_sum[i]]--;
  }
  cout << res << endl;
  return 0;
}
#endif
