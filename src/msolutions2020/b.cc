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
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  while (k and b <= a) {
    b *= 2;
    k--;
  }
  while (k and c <= b) {
    c *= 2;
    k--;
  }
  if (b > a && c > b) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;

  return 0;
}
#endif
