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
  string s;
  cin >> s;
  if (s[0] == '1') {
    cout << "No" << endl;
    return 0;
  }

  vector<vector<int>> g(7);
  g[0] = {6};
  g[1] = {3};
  g[2] = {1, 7};
  g[3] = {0, 4};
  g[4] = {2, 8};
  g[5] = {5};
  g[6] = {9};
  vector<bool> a(7);
  for (int i = 0; i < 7; i++) {
    bool ok = true;
    for (int j : g[i]) {
      if (s[j] == '1')
        ok = false;
    }
    a[i] = ok;
  }
  for (int i = 1; i < 6; i++) {
    if (a[i]) {
      int exist = 0;
      for (int j = 0; j < i; j++) {
        if (a[j] == false) {
          exist++;
          break;
        }
      }
      for (int j = i + 1; j < 7; j++) {
        if (a[j] == false) {
          exist++;
          break;
        }
      }
      if (exist > 1) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
#endif
