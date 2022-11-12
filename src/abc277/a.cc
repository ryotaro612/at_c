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
  int x;

  cin >> n >> x;
  vector<int> pv(n);
  rep(i, n) {
    cin >> pv[i];
    if (pv[i] == x) {
      cout << i + 1 << endl;
      return 0;
    }
  }

  return 0;
}
#endif
