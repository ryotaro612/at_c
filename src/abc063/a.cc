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
  int a, b;
  cin >> a >> b;
  if (a + b >= 10)
    cout << "error";
  else
    cout << a + b;
  cout << endl;
  return 0;
}
#endif
