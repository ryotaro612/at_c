#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <limits>
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

int sub(int n, int target, vector<vector<int>> &reels) {
  unordered_set<int> done;
  for (int t = 0;; t++) {
    bool consumed = false;
    rep(i, n) {
      if (done.find(i) == done.end() && !consumed) {
        if (reels[i][t % 10] == target) {
          done.insert(i);
          consumed = true;
        }
      }
    }
    // cout << t << " -> " << done.size() << endl;
    if ((int)done.size() == n)
      return t;
  }
}

int solve(int n, vector<string> &sv) {
  int res = numeric_limits<int>::max();
  vector<vector<int>> reels(n, vector<int>(10));
  rep(j, n) {
    rep(k, 10) { reels[j][k] = sv[j][k] - '0'; }
  }
  rep(i, 10) {
    int temp = sub(n, i, reels);
    // cout << i << " -> " << temp << endl;
    res = min(temp, res);
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  cout << solve(n, sv) << endl;
  return 0;
}
#endif
