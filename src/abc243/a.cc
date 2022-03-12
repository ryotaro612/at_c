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
  int v, a, b, c;
  cin >> v >> a >> b >> c;
  v %= a + b + c;
  v -= a;
  if (v < 0) {
    cout << "F" << endl;
    return 0;
  }
  v -= b;
  if (v < 0) {
    cout << "M" << endl;
    return 0;
  }

  cout << "T" << endl;
  return 0;
}
#endif
