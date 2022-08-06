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
  vector<int> pv(n - 1);
  rep(i, n - 1) { cin >> pv[i]; }
  int res = 1;
  int p = pv[n - 2];
  while (p != 1) {
    p = pv[p - 2];
    res++;
  }
  cout << res << endl;
  return 0;
}
#endif
