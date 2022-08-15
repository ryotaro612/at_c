#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> pv(n * 2);
  rep(i, 2 * n) cin >> pv[i];
  vector<int> xv;
  for (int i = 1; i < 2 * n - 1; i += 2) {
    if (pv[i - 1] > pv[i]) {
      if (pv[i] < pv[i + 1]) {
        if (pv[i - 1] > pv[i + 1]) {
          swap(pv[i - 1], pv[i]);
          xv.push_back(i);
        } else {
          swap(pv[i], pv[i + 1]);
          xv.push_back(i + 1);
        }
      }
    }
  }

  for (int i = 0; i < 2 * n - 1; i++) {
    if (i % 2 == 0 && pv[i] > pv[i + 1]) {
      swap(pv[i], pv[i + 1]);
      xv.push_back(i + 1);
    } else if (i % 2 == 1 && pv[i] < pv[i + 1]) {
      swap(pv[i], pv[i + 1]);
      xv.push_back(i + 1);
    }
  }

  cout << xv.size() << endl;
  rep(i, xv.size()) {
    cout << xv[i];
    if (i == (int)xv.size())
      cout << endl;
    else
      cout << " ";
  }

  return 0;
}
#endif
