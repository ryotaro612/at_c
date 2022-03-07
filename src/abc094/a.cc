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
  int a, b, x;
  cin >> a >> b >> x;
  if (a <= x && x <= a + b)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}
#endif
