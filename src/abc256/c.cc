#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<vector<int>> compute_combi(int triple) {
  vector<vector<int>> res;
  for (int i = 1; i <= triple - 2; i++) {
    for (int j = 1; j <= triple - 2; j++) {
      for (int k = 1; k <= triple - 2; k++) {
        if (i + j + k == triple) {
          res.push_back({i, j, k});
        }
      }
    }
  }
  return res;
}

ll solve(vector<int> hv, vector<int> wv) {
  vector<vector<int>> h1 = compute_combi(hv[0]);
  vector<vector<int>> h2 = compute_combi(hv[1]);
  vector<vector<int>> h3 = compute_combi(hv[2]);
  ll res = 0;

  for (auto e1 : h1) {
    for (auto e2 : h2) {
      for (auto e3 : h3) {
        if (e1[0] + e2[0] + e3[0] == wv[0] && e1[1] + e2[1] + e3[1] == wv[1] &&
            e1[2] + e2[2] + e3[2] == wv[2])
          res++;
      }
    }
  }

  return res;
}

#ifdef ONLINE_JUDGE
int main() {

  vector<int> hv(3), wv(3);
  rep(i, 3) { cin >> hv[i]; }
  rep(i, 3) { cin >> wv[i]; }
  cout << solve(hv, wv) << endl;
  return 0;
}
#endif
