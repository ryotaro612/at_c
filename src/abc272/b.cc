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
  int n, m;
  cin >> n >> m;
  vector<set<int>> men(n);
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int x;
      cin >> x;
      men[--x].insert(i);
    }
  }
  rep(i, n) {

    rep(j, n) {
      bool ok = false;
      for (auto e : men[j]) {
        if (men[i].find(e) != men[i].end()) {
          ok = true;
        }
      }
      if (ok == false) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
