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
  int n;
  cin >> n;
  vector<ll> hv(n);
  rep(i, n) cin >> hv[i];
  int result = 0;
  rep(i, n) {
    if (hv[i] > hv[result]) {
      result = i;
    }
  }
  cout << result + 1 << endl;

  return 0;
}
#endif
