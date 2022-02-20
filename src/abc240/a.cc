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
  int a, b;
  cin >> a >> b;

  if (abs(a - b) == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  if ((a == 1 && b == 10) || (a == 10 && b == 1)) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
#endif
