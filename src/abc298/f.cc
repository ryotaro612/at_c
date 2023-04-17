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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<ll> rv(n), cv(n), xv(n);
  map<ll, ll> row_sum, col_sum;
  map<pair<ll, ll>, ll> rc_val;
  rep(i, n) {
    cin >> rv[i] >> cv[i] >> xv[i];
    row_sum[rv[i]] += xv[i];
    col_sum[cv[i]] += xv[i];
    rc_val[{rv[i], cv[i]}] = xv[i];
  }
  vector<pair<ll, ll>> sum_cols(n);
  for (auto [col, total] : col_sum)
    sum_cols.push_back({total, col});
  sort(sum_cols.begin(), sum_cols.end(), greater<pair<ll, ll>>());

  ll res = 0;
  for (auto [row, total] : row_sum) {
    for (auto [col_sum, col] : sum_cols) {
      if (rc_val[{row, col}] == 0) {
        res = max(res, col_sum + total);
        break;
      } else {
        res = max(res, col_sum + total - rc_val[{row, col}]);
      }
    }
  }

  cout << res << endl;

  return 0;
}
#endif
