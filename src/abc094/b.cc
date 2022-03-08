#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> av(m);
  rep(i, m) cin >> av[i];
  int res = 0;
  for (int i = x; i < n; i++) {
    rep(j, m) {
      if (av[j] == i)
        res++;
    }
  }
  int candidate = 0;
  for (int i = x; 0 < i; i--) {
    rep(j, m) {
      if (av[j] == i)
        candidate++;
    }
  }
  res = min(res, candidate);
  cout << res << endl;

  return 0;
}
#endif
