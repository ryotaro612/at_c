#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

void rec(int i, int aim, int n, vector<int> &acc, vector<vector<int>> &res) {
  if ((int)acc.size() == aim) {
    res.push_back(vector<int>(acc));
    return;
  }
  if (i == n) {
    return;
  }

  acc.push_back(i);
  rec(i + 1, aim, n, acc, res);
  acc.pop_back();
  rec(i + 1, aim, n, acc, res);
}

vector<vector<int>> enum_patterns(int aim, int n) {
  // cout << aim << " " << n << endl;

  vector<vector<int>> res;
  vector<int> acc;
  rec(0, aim, n, acc, res);
  return res;
}

string solve(int ha, int wa, vector<vector<ll>> &am, int hb, int wb,
             vector<vector<ll>> &bm) {
  if (ha < hb || wa < wb) {
    return "No";
  }
  vector<vector<int>> rows = enum_patterns(hb, ha);
  // for (auto row_idx : rows) {
  //   for (auto r : row_idx) {
  //     cout << r << " ";
  //   }
  //   cout << endl;
  // }
  vector<vector<int>> cols = enum_patterns(wb, wa);
  for (vector<int> row_idx : rows) {
    for (vector<int> col_idx : cols) {

      vector<vector<ll>> min_a;
      for (int row_i : row_idx) {
        min_a.push_back(vector<ll>());
        for (int col_i : col_idx) {
          min_a.back().push_back(am[row_i][col_i]);
        }
      }
      bool ok = true;
      rep(i, hb) {
        rep(j, wb) {
          if (min_a[i][j] != bm[i][j]) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        return "Yes";
      }
    }
  }
  return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  int ha, wa;
  cin >> ha >> wa;
  vector<vector<ll>> am(ha, vector<ll>(wa));
  rep(i, ha) {
    rep(j, wa) { cin >> am[i][j]; }
  }
  int hb, wb;
  cin >> hb >> wb;
  vector<vector<ll>> bm(hb, vector<ll>(wb));
  rep(i, hb) {
    rep(j, wb) { cin >> bm[i][j]; }
  }
  cout << solve(ha, wa, am, hb, wb, bm) << endl;

  return 0;
}
#endif
