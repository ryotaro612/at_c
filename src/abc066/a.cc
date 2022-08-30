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
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  sort(a.begin(), a.end());
  cout << a[0] + a[1] << endl;
  return 0;
}
#endif
