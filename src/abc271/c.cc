
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

  int ub = n + 1, lb = -1;

  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    int count = 0;
    map<ll, bool> mp;
    rep(i, n) {
      if (mp[av[i]] || mid < av[i])
        count++;
      else
        mp[av[i]] = true;
    }
    // cout << mid << " mid " << count << " count " << endl;

    int i = 1;
    while (true) {
      if (mp[i])
        i++;
      else if (count >= 2) {
        count -= 2;
        i++;
      } else {
        break;
      }
    }
    // cout << " i " << i << " mid" << mid << endl;
    if (mid <= i - 1) {
      lb = mid;
    } else {
      ub = mid;
    }
    // cout << ub << " " << lb << endl;
  }
  cout << lb << endl;
  return 0;
}
#endif
