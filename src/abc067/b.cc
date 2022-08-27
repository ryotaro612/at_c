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
  int n, k;
  cin >> n >> k;
  vector<int> lv(n);
  rep(i, n) cin >> lv[i];
  sort(lv.begin(), lv.end(), greater<ll>());
  int res = 0;
  rep(i, k) { res += lv[i]; }
  cout << res << endl;

  return 0;
}
#endif
