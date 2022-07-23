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
  vector<string> av(n);
  rep(i, n) { cin >> av[i]; }
  rep(i, n) {
    rep(j, n) {
      if (i == j)
        continue;
      bool ok = true;
      if (av[i][j] == 'W') {
        if (av[j][i] != 'L') {
          ok = false;
        }
      } else if (av[i][j] == 'L') {
        if (av[j][i] != 'W') {
          ok = false;
        }
      } else {
        if (av[j][i] != 'D')
          ok = false;
      }
      if (!ok) {
        cout << "incorrect" << endl;
        return 0;
      }
    }
  }
  cout << "correct" << endl;
  return 0;
}
#endif
