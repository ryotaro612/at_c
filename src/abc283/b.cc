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
  cin >> n;
  vector<ll> av(n);
  rep(i, n) cin >> av[i];
  int q;
  cin >> q;
  rep(i, q) {
    int inst, k;
    cin >> inst >> k;
    k--;
    if (inst == 1) {
      ll x;
      cin >> x;
      av[k] = x;
    } else {
      cout << av[k] << endl;
    }
  }
  return 0;
}
#endif
