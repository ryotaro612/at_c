#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a < c) {
    cout << "Takahashi" << endl;
    return 0;
  } else if (c < a) {
    cout << "Aoki" << endl;
    return 0;
  }
  if (b <= d) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
#endif
