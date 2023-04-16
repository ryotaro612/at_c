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
bool ok(vector<vector<int>> &am, vector<vector<int>> &bm) {
  int n = am[0].size();
  rep(i, n) {
    rep(j, n) {
      if (bm[i][j] == 0 && am[i][j] == 1)
        return false;
    }
  }
  return true;
}
void rotate(vector<vector<int>> &m) {
  int n = m[0].size();
  vector<vector<int>> a = vector(n, vector<int>(n));
  rep(i, n) {
    rep(j, n) { a[i][j] = m[n - 1 - j][i]; }
  }
  rep(i, n) {
    rep(j, n) { m[i][j] = a[i][j]; }
  }
  // rep(i, n) {
  //   rep(j, n) { cout << m[i][j] << " "; }
  //   cout << endl;
  // }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<vector<int>> am(n, vector<int>(n)), bm(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> am[i][j];
  rep(i, n) rep(j, n) cin >> bm[i][j];
  rep(i, 4) {

    if (ok(am, bm)) {
      cout << "Yes" << endl;
      return 0;
    }
    rotate(am);
  }
  cout << "No\n";
  return 0;
}
#endif
