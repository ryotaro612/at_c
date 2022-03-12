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
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> av(n);
  rep(i, n) cin >> av[i];

  int res = x;
  rep(i, n) {
    for (int j = 0; j * av[i] + 1 <= d; j++) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
#endif
