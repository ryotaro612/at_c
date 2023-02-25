#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  if (abs(b - c) > 1) {
    cout << "No" << endl;
    return 0;
  }
  if (a && d && b == 0 && c == 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  return 0;
}
#endif
