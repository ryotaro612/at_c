#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

bool is_ok(int i, vector<int> &pv) {
  if (pv[i] % 2) {
    if (i % 2)
      return false;
  } else {
    if (i % 2 == 0)
      return false;
  }
  return true;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> pv(n);
  rep(i, n) cin >> pv[i];
  vector<pair<char, int>> res;

  while (true) {
    bool ok = true;
    rep(i, n) {
      if (!is_ok(i, pv)) {
        ok = false;
        if (i < n - 1) {
          if (!is_ok(i + 1, pv)) {
            swap(pv[i], pv[i + 1]);
            res.push_back({'A', i + 1});
          } else {
            if (i < n - 2) {
              swap(pv[i], pv[i + 2]);
              res.push_back({'B', i + 1});
            }
          }
        }
      }
    }
    if (ok)
      break;
  }
  for (int p = 1; p <= n; p++) {
    for (int i = 0; i < n; i++) {
      if (pv[i] == p) {
        int j = i;
        while (j + 1 != p) {
          if (j + 1 < p) {
            res.push_back({'B', j + 1});
            swap(pv[j], pv[j + 2]);
            j += 2;
          } else { // p < j + 1
            res.push_back({'B', j - 1});
            swap(pv[j - 2], pv[j]);
            j -= 2;
          }
        }
      }
    }
  }

  rep(i, n) { assert(pv[i] == i + 1); }

  cout << res.size() << endl;
  for (auto [c, a] : res)
    cout << c << " " << a << endl;
  return 0;
}
#endif
