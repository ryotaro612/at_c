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

vector<vector<ll>> mat(vector<vector<ll>> am, vector<vector<ll>> bm, ll mod) {
  vector<vector<ll>> res(2, vector<ll>(2));
  // cout << " mul " << endl;
  // cout << am[0][0] << " " << am[0][1] << endl;
  // cout << am[1][0] << " " << am[1][1] << endl;
  // cout << "x" << endl;
  // cout << bm[0][0] << " " << bm[0][1] << endl;
  // cout << bm[1][0] << " " << bm[1][1] << endl;
  res[0][0] = am[0][0] * bm[0][0] % mod + am[0][1] * bm[1][0] % mod;
  res[0][1] = am[0][0] * bm[0][1] % mod + am[0][1] * bm[1][1] % mod;
  res[1][0] = am[1][0] * bm[0][0] % mod + am[1][1] * bm[1][0] % mod;
  res[1][1] = am[1][0] * bm[0][1] % mod + am[1][1] * bm[1][1] % mod;
  rep(i, 2) {
    rep(j, 2) { res[i][j] %= mod; }
  }
  // cout << "res" << endl;
  // cout << res[0][0] << " " << res[0][1] << endl;
  // cout << res[1][0] << " " << res[1][1] << endl;
  return res;
}

vector<vector<ll>> mul_mat(ll a, ll n, ll m) {
  vector<vector<ll>> res = {{1, 0}, {0, 1}}, am = {{a, 1}, {0, 1}};
  while (n) {
    if (n & 1)
      res = mat(am, res, m);
    am = mat(am, am, m);
    n >>= 1;
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  ll a, x, m;
  cin >> a >> x >> m;
  vector<vector<ll>> matrix = mul_mat(a, x - 1, m);
  // cout << matrix[0][0] << " " << matrix[0][1] << endl;
  // cout << matrix[1][0] << " " << matrix[1][1] << endl;
  cout << (matrix[0][0] + matrix[0][1]) % m << endl;
  return 0;
}
#endif
