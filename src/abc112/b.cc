#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, t;
  cin >> n >> t;
  int res = 1 << 30;
  rep(i, n) {
    int c, tt;
    cin >> c >> tt;
    if (tt <= t) {
      res = min(res, c);
    }
  }
  if (res == 1 << 30)
    cout << "TLE" << endl;
  else
    cout << res << endl;
  return 0;
}
