#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ld solve(int a, int b, int c, int x) {
  if (x <= a) {
    return 1;
  } else if (x <= b) {
    return (ld)c / ((ld)b - (ld)a);
  } else
    return 0;
}

#ifdef ONLINE_JUDGE
int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  cout << fixed << solve(a, b, c, x) << endl;
  return 0;
}
#endif
