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
  vector<int> update(n, -1);
  int q;
  cin >> q;
  int assign_t = -2ll;
  ll assign = 0ll;
  rep(j, q) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> assign;
      assign_t = j;
    } else if (t == 2) {
      ll i, x;
      cin >> i >> x;
      i--;
      if (update[i] < assign_t) {
        // cout << j << " !" << endl;
        av[i] = assign;
        update[i] = j;
      }
      av[i] += x;
    } else {
      int i;
      cin >> i;
      i--;
      if (update[i] < assign_t)
        cout << assign;
      else
        cout << av[i];
      cout << endl;
    }
  }
  return 0;
}
#endif
