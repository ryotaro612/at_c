#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); i++)

vector<int> solve(int n, int c, vector<int> &tv, vector<int> &av) {
  vector<int> dp_p(n + 1), dp_n(n + 1);
  int a = (1 << 30) - 1;
  dp_p[0] = a;
  dp_n[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (tv[i - 1] == 1) {
      dp_p[i] = dp_p[i - 1] & av[i - 1];
      dp_n[i] = dp_n[i - 1] & av[i - 1];
    } else if (tv[i - 1] == 2) {
      dp_p[i] = dp_p[i - 1] | av[i - 1];
      dp_n[i] = dp_n[i - 1] | av[i - 1];
    } else {
      dp_p[i] = dp_p[i - 1] ^ av[i - 1];
      dp_n[i] = dp_n[i - 1] ^ av[i - 1];
    }
  }
  // rep(i, n + 1) { cout << dp_p[i] << " " << dp_n[i] << endl; }
  // cout << "----" << endl;

  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    int e = 0;
    for (int j = 0; j < 30; j++) {
      if (c & (1 << j)) {
        if (dp_p[i + 1] & (1 << j)) {
          e |= 1 << j;
        }
      } else { // negative
        if (dp_n[i + 1] & (1 << j)) {
          e |= 1 << j;
        }
      }
    }
    res[i] = e;
    c = e;
  }
  return res;
}

//#ifdef ONLINE_JUDGE
int main() {
  int n, c;
  cin >> n >> c;
  vector<int> tv(n), av(n);
  rep(i, n) cin >> tv[i] >> av[i];
  vector<int> res = solve(n, c, tv, av);
  for (auto e : res)
    cout << e << endl;

  return 0;
}
