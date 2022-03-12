#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> av(n), bv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  int res1 = 0;
  rep(i, n) {
    if (av[i] == bv[i])
      res1++;
  }
  int res2 = 0;
  rep(i, n) {

    rep(j, n) {
      if (av[i] == bv[j] && i != j) {
        res2++;
        break;
      }
    }
  }
  cout << res1 << endl;
  cout << res2 << endl;
  return 0;
}
#endif
