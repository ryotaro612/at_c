#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#include <algorithm>
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
  vector<int> cv(9);
  rep(i, 9) { cin >> cv[i]; }
  int mi = *min_element(cv.begin(), cv.end());
  int length = n / mi;
  string res = "";
  rep(i, length) {
    for (int j = 8; j >= 0; j--) {
      if (cv[j] + mi * (length - i - 1) <= n) {
        res.push_back('0' + j + 1);
        n -= cv[j];
        break;
      }
    }
  }
  cout << res << endl;

  return 0;
}
#endif
