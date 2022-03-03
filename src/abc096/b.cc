#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//#ifdef ONLINE_JUDGE
int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int m = max(a, max(b, c));
  rep(i, k) { m *= 2; }
  int res = a + b + c + m - max(a, max(b, c));
  cout << res << endl;

  return 0;
}
//#endif
