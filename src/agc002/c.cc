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

// #ifdef ONLINE_JUDGE
int main() {
  ll n;
  ll l;
  ll aa[100001];
  cin >> n >> l;
  rep(i, n) cin >> aa[i];

  rep(i, n) {
    if (aa[i] >= l) {
      cout << "Possible\n";
      for (int j = 1; j <= i; j++)
        cout << j << endl;
      for (int j = n - 1; j >= i + 1; j--)
        cout << j << endl;
      return 0;
    }
  }
  rep(i, n - 1) {
    if (aa[i] + aa[i + 1] >= l) {
      cout << "Possible\n";
      for (int j = 1; j <= i; j++)
        cout << j << endl;
      for (int j = n - 1; j >= i + 1; j--)
        cout << j << endl;
      return 0;
    }
  }
  cout << "Impossible\n";

  return 0;
}
// #endif
