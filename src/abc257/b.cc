#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<int> solve(int n, int k, int q, vector<int> &av, vector<int> &lv) {
  vector<bool> masu(n);
  rep(i, k) { masu[--av[i]] = true; }
  rep(i, q) {
    int l = lv[i];
    int count = 0;
    int pos = 0;
    for (; pos < n; pos++) {
      if (masu[pos] == true)
        count++;
      if (count == l)
        break;
    }
    if (pos < n - 1 && masu[pos + 1] == false) {
      masu[pos] = false;
      masu[pos + 1] = true;
    }
  }
  vector<int> res;
  rep(i, n) {
    if (masu[i]) {
      res.push_back(i + 1);
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> av(k), lv(q);
  rep(i, k) cin >> av[i];
  rep(i, q) cin >> lv[i];

  vector<int> res = solve(n, k, q, av, lv);
  rep(i, k) {
    cout << res[i];
    if (i == k - 1)
      cout << endl;
    else
      cout << " ";
  }

  return 0;
}
#endif
