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
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  vector<bool> masu1(101, false), masu2(101, false);
  for (int i = l1; i <= r1; i++) {
    masu1[i] = true;
  }
  for (int i = l2; i <= r2; i++) {
    masu2[i] = true;
  }
  int res = 0;
  rep(i, 101) {
    if (masu1[i] && masu2[i])
      res++;
  }
  cout << max(0, res - 1) << endl;
  return 0;
}
#endif
