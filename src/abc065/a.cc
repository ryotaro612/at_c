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
  ll x, a, b;
  cin >> x >> a >> b;
  if (b <= a)
    cout << "delicious";
  else if (b - a <= x)
    cout << "safe";
  else
    cout << "dangerous";
  cout << endl;
  return 0;
}
#endif
