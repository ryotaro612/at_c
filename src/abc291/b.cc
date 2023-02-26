#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <iomanip>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ld> xv(5 * n);
  ld res = 0;
  rep(i, 5 * n) { cin >> xv[i]; }
  sort(xv.begin(), xv.end());
  for (int i = n; i < 4 * n; i++) {
    res += xv[i];
  }
  cout << fixed << setprecision(12) << res / (3.0 * (ld)n) << endl;
  return 0;
}
#endif
