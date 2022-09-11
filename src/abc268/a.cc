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
  vector<int> a(5);
  rep(i, 5) cin >> a[i];
  set<int> s(a.begin(), a.end());
  cout << s.size() << endl;
  return 0;
}
#endif
