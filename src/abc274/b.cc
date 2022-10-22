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
  int h, w;
  cin >> h >> w;
  vector<string> cm(h);
  rep(i, h) { cin >> cm[i]; }
  vector<int> res(w);
  rep(i, w) {
    int c = 0;
    rep(j, h) {
      if (cm[j][i] == '#')
        c++;
    }
    res[i] = c;
  }
  rep(i, w) {
    cout << res[i];
    if (i < w - 1)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}
#endif
