#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<int> prefix(200001, 0);
vector<pair<int, int>> solve(int n, vector<int> &lv, vector<int> &rv) {
  rep(i, n) {
    prefix[lv[i]] += 1;
    prefix[rv[i]] -= 1;
  }
  int size = static_cast<int>(prefix.size());
  for (int i = 1; i < size; i++) {
    prefix[i] += prefix[i - 1];
  }
  vector<pair<int, int>> res;
  int part;
  for (int i = 1; i < size; i++) {
    if (prefix[i - 1] == 0 && prefix[i] > 0) {
      part = i;
    } else if (prefix[i - 1] > 0 && prefix[i] == 0) {
      res.push_back({part, i});
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {

  int n;
  cin >> n;
  vector<int> lv(n), rv(n);
  rep(i, n) cin >> lv[i] >> rv[i];
  vector<pair<int, int>> res = solve(n, lv, rv);
  for (auto [l, r] : res) {
    cout << l << " " << r << endl;
  }
  return 0;
}
#endif
