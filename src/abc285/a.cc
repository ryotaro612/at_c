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
  int a, b;
  cin >> a >> b;
  if (a * 2 == b || a * 2 + 1 == b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
#endif
