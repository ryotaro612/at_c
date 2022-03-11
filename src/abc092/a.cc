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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(a, b) + min(c, d) << endl;
  return 0;
}
#endif
