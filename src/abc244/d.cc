#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  vector<char> sv(3), tv(3);
  rep(i, 3) cin >> sv[i];
  rep(i, 3) cin >> tv[i];

  vector<vector<char>> cands = {
      {sv[0], sv[1], sv[2]}, {sv[2], sv[0], sv[1]}, {sv[1], sv[2], sv[0]}};

  rep(i, cands.size()) {
    if (tv == cands[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  // if ((sv[0] == tv[0] && sv[1] == tv[1] && sv[2] == tv[2]) ||
  //     (sv[2] == tv[0] && sv[1] == tv[1] && sv[2] == tv[2])) {
  //   cout << "Yes";
  // } else
  //   cout << "No";
  // cout << endl;
  return 0;
}
#endif
