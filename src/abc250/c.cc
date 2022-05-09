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
  int n, q;
  cin >> n >> q;
  vector<int> xv(q);
  rep(i, q) {
    cin >> xv[i];
    xv[i]--;
  }

  vector<int> ball_to_pos(n);
  rep(i, n) ball_to_pos[i] = i;
  vector<int> res(n);
  rep(i, n) { res[i] = i + 1; }

  rep(i, q) {
    int pos = ball_to_pos[xv[i]];
    if (pos == n - 1) {
      int ball = res[pos], ball2 = res[pos - 1];
      res[pos] = ball2;
      res[pos - 1] = ball;
      ball_to_pos[ball2 - 1] = pos;
      ball_to_pos[ball - 1] = pos - 1;
    } else {
      int ball = res[pos], ball2 = res[pos + 1];
      res[pos] = ball2;
      res[pos + 1] = ball;
      ball_to_pos[ball2 - 1] = pos;
      ball_to_pos[ball - 1] = pos + 1;
    }
  }

  rep(i, n) {
    cout << res[i];
    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
#endif
