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
int aa[101];
#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> aa[i];
  rep(i, n) {
    if (i == n - 1) {
      cout << aa[i] << endl;
    } else if (aa[i] < aa[i + 1]) {
      for (int j = aa[i]; j < aa[i + 1]; j++)
        cout << j << " ";
    } else {
      for (int j = aa[i]; j > aa[i + 1]; j--)
        cout << j << " ";
    }
  }
  return 0;
}
#endif
