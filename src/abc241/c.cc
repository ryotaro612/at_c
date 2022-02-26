#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string solve(int n, vector<string> &sv) {

  rep(i, n) {
    int count_c = 0;
    int count_r = 0;
    rep(j, n) {
      if (sv[i][j] == '#')
        count_c++;
      if (6 <= j && sv[i][j - 6] == '#')
        count_c--;
      if (4 <= count_c)
        return "Yes";

      if (sv[j][i] == '#')
        count_r++;
      if (6 <= j && sv[j - 6][i] == '#')
        count_r--;
      if (4 <= count_r)
        return "Yes";
    }
  }
  rep(i, n - 5) {
    rep(j, n - 5) {
      int count = 0;
      rep(k, 6) {
        if (sv[i + k][j + k] == '#')
          count++;
      }
      if (4 <= count)
        return "Yes";
    }
  }

  rep(i, n - 5) {
    for (int j = n - 1; j >= 5; j--) {
      int count = 0;
      rep(k, 6) {
        if (sv[i + k][j - k] == '#')
          count++;
      }
      if (4 <= count)
        return "Yes";
    }
  }

  return "No";
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) { cin >> sv[i]; }
  cout << solve(n, sv) << endl;
  return 0;
}
#endif
